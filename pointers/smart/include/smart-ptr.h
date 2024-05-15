
#pragma once

#include <iostream>
#include <functional>
#include <memory>

//RAII

namespace smart_ptr
{

    struct xUnSetResource {};

    template<typename T>
    class ResourceHolder
    {
        T* data_;
        int usage_count_;

    public:
        explicit ResourceHolder(T* data)
        : data_(data)
        ,usage_count_(1)
        {}

        ~ResourceHolder()
        {
            delete data_;
        }

        T& get()
        {
            return *data_;
        }

        const T& get() const
        {
            return *data_;
        }

        T& operator*()
        {
            return get();
        }

        const T& operator*() const
        {
            return get();
        }

        T* operator->() const
        {
            return data_;
        }

        ResourceHolder& operator++()
        {
            ++usage_count_;
            return *this;
        }

        ResourceHolder& operator--()
        {
            --usage_count_;
            return *this;
        }

        [[nodiscard]] const int& usage_count() const
        {
            return usage_count_;
        }

        template<typename V>
        friend bool operator==(const ResourceHolder<V>& lhs, const ResourceHolder<V>& rhs);

        template<typename V>
        friend bool operator==(const ResourceHolder<V>& lhs, const int& usage_count);
    };

    template<typename T>
    bool operator==(const ResourceHolder<T>& lhs, const ResourceHolder<T>& rhs)
    {
        return lhs.data_ == rhs.data_;
    }

    template<typename T>
    bool operator==(const ResourceHolder<T>& lhs, const int& usage_count)
    {
        return lhs.usage_count_ == usage_count;
    }

    template<typename T>
    class SmartPtr final
    {
       ResourceHolder<T> *resource_holder;
    protected:
        void try_to_clear()
        {
            if (resource_holder && --*resource_holder == 0)
            {
                delete resource_holder;
            }
        }
    public:
        explicit SmartPtr(T* data = nullptr)
        : resource_holder(nullptr)
        {
            if (data)
            {
                resource_holder = new ResourceHolder<T>(data);
            }
        }

       SmartPtr(const SmartPtr& rhs)
           : resource_holder(rhs.resource_holder)
       {
            if (resource_holder)
            {
                ++*resource_holder;
            }
       }

       SmartPtr(SmartPtr&& rhs) noexcept
           : resource_holder(rhs.resource_holder)
       {
            rhs.resource_holder = nullptr;
       }

        ~SmartPtr()
        {
            try_to_clear();
        }

       SmartPtr& operator=(const SmartPtr& rhs)
       {
           if (this == &rhs)
               return *this;

            try_to_clear();

            resource_holder = rhs.resource_holder;

            if (resource_holder)
            {
                ++*resource_holder;
            }

            return *this;
       }

        SmartPtr& operator=(const T* data)
        {
            try_to_clear();

            resource_holder = new ResourceHolder<T>(data);

            return *this;
        }

       SmartPtr& operator=(SmartPtr&& rhs) noexcept
       {
            if (this == &rhs)
            {
               return *this;
            }

            try_to_clear();

            resource_holder = rhs.resource_holder;

            rhs.resource_holder = nullptr;

            return *this;
       }

        T& operator*()
        {

            return resource_holder->get();
        }

        const T& operator*() const
        {
            return resource_holder->get();
        }

        const T& get() const
        {
            return resource_holder->get();
        }

        [[nodiscard]] const int& usage_count() const
        {
            return resource_holder->usage_count();
        }
    };

    template<typename T, typename... Args>
    SmartPtr<T> make_smart(Args... args)
    {
        return SmartPtr<T>(new T(std::forward<Args>(args)...));
    }
}
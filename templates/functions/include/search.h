
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <exception>
#include <functional>
#include <cstdlib>
#include <cmath>

template<typename T, typename K, int size>
int find_by(T(&a)[size], const K& key)
{
    for (int i = 0; i < size; ++i)
    {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

template<typename K, int size>
int find_by(double(&a)[size], const K & key)
{
    for (int i = 0; i < size; ++i)
    {
        if (fabs(a[i] - key) < 1e-9) {
            return i;
        }
    }
    return -1;
}


//int find_by(int a[], int size, int key)
//{
//    for (int i = 0; i < size; ++i)
//    {
//        if (a[i] == key) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int find_by(double a[], int size, double key)
//{
//    for (int i = 0; i < size; ++i)
//    {
//        if (a[i] == key) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int find_by(string a[], int size, string key)
//{
//    for (int i = 0; i < size; ++i)
//    {
//        if (a[i] == key) {
//            return i;
//        }
//    }
//    return -1;
//}


#pragma once

#include "shapes.h"
#include <iostream>

namespace shapes {

	namespace context {
	
		class ShapeDrawer {
		protected:
			const Shape2D& shape;
		public:
			ShapeDrawer(const Shape2D& shape_): shape(shape_) {}

			const Shape2D& get_shape() const
			{
				return shape;
			}

			virtual void draw() const = 0;
		};


		class ConsoleShapeDrawer : public ShapeDrawer
		{
		protected:
			std::ostream& os;
		public:
			ConsoleShapeDrawer(const Shape2D& shape_, std::ostream& os_): ShapeDrawer(shape_), os(os_)
			{}
		};

		class RectangleConsoleShapeDrawer : public ConsoleShapeDrawer
		{
		private:
			void horizontal(const Rectangle& r) const
			{
				for (int i = 0; i < r.getW(); ++i)
				{
					os << "*";

					if (i < r.getW() - 1)
					{
						os << " ";
					}
				}

				os << "\n";
			}

			void vertical(const Rectangle& r) const
			{
				for (int j = 0; j < r.getH() - 2; ++j)
				{
					os << "*";

					for (int k = 1; k < 2*(r.getW() - 1); ++k)
					{
						os << " ";
					}

					os << "*\n";
				}
			}

		public:
			RectangleConsoleShapeDrawer(const Rectangle& r, std::ostream& os_): ConsoleShapeDrawer(r, os_)
			{}

			void draw() const override
			{
				auto& r = (( const Rectangle&)shape);

				horizontal(r);

				vertical(r);

				horizontal(r);
			}
		};
	}
}
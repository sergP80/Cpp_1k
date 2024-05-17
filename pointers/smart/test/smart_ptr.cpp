#include "gtest/gtest.h"
#include "smart-ptr.h"
#include "point.h"
#include <cmath>

TEST(SmartPtrSuite, IntPoint2D) {

    using smart_ptr::SmartPtr;
    using smart_ptr::make_smart;
    using geometry::Point;

   auto int_pt1 = make_smart<Point<int>>(12, 14);

  EXPECT_EQ(12, int_pt1->x);
  EXPECT_EQ(14, int_pt1->y);
}

TEST(SmartPtrSuite, RealPoint2D) {

    using smart_ptr::SmartPtr;
    using smart_ptr::make_smart;
    using geometry::Point;

    auto real_pt1 = make_smart<Point<double>>(12.4, 14.5);

    EXPECT_NEAR(12.4, real_pt1->x, 1e-5);
    EXPECT_NEAR(14.5, real_pt1->y, 1e-5);
}

TEST(SmartPtrSuite, DistanceRealPoint2D) {

    using smart_ptr::SmartPtr;
    using smart_ptr::make_smart;
    using geometry::Point;
    using std::sqrt;

    auto real_pt1 = make_smart<Point<double>>(12.4, 14.5);

    auto real_pt2 = make_smart<Point<double>>(5.4, -4.3);

    constexpr auto expect = 20.06091;

    EXPECT_NEAR(expect, real_pt1->distance(*real_pt2), 1e-5);
}
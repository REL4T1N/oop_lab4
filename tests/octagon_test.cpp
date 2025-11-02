#include <gtest/gtest.h>
#include "../include/octagon.h"

TEST(OctagonTest, Constructors) {
    Point<double> center(0, 0);
    Octagon<double> o(center, 5.0);
    
    ASSERT_GT(o.area(), 0.0);
}

TEST(OctagonTest, Area) {
    Point<double> center(0, 0);
    Octagon<double> o(center, 5.0);
    double area = o.area();
    
    ASSERT_GT(area, 0.0);
}

TEST(OctagonTest, GetCenter) {
    Point<double> center(2.0, 3.0);
    Octagon<double> o(center, 5.0);
    Point<double> retrieved_center = o.getCenter();
    
    ASSERT_DOUBLE_EQ(retrieved_center.x, 2.0);
    ASSERT_DOUBLE_EQ(retrieved_center.y, 3.0);
}

TEST(OctagonTest, Comparison) {
    Point<double> center1(0, 0);
    Point<double> center2(1, 1);
    
    Octagon<double> o1(center1, 5.0);
    Octagon<double> o2(center1, 5.0);
    Octagon<double> o3(center2, 5.0);
    
    ASSERT_TRUE(o1 == o2);
    ASSERT_FALSE(o1 == o3);
}
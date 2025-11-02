#include <gtest/gtest.h>
#include "../include/pentagon.h"

TEST(PentagonTest, Constructors) {
    Point<double> center(0, 0);
    Pentagon<double> p(center, 5.0);
    
    ASSERT_GT(p.area(), 0.0);
}

TEST(PentagonTest, Area) {
    Point<double> center(0, 0);
    Pentagon<double> p(center, 5.0);
    double area = p.area();
    
    ASSERT_GT(area, 0.0);
}

TEST(PentagonTest, GetCenter) {
    Point<double> center(2.0, 3.0);
    Pentagon<double> p(center, 5.0);
    Point<double> retrieved_center = p.getCenter();
    
    ASSERT_DOUBLE_EQ(retrieved_center.x, 2.0);
    ASSERT_DOUBLE_EQ(retrieved_center.y, 3.0);
}

TEST(PentagonTest, Comparison) {
    Point<double> center1(0, 0);
    Point<double> center2(1, 1);
    
    Pentagon<double> p1(center1, 5.0);
    Pentagon<double> p2(center1, 5.0);
    Pentagon<double> p3(center2, 5.0);
    
    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 == p3);
}
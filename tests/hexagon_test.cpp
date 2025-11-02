#include <gtest/gtest.h>
#include "../include/hexagon.h"

TEST(HexagonTest, Constructors) {
    Point<double> center(0, 0);
    Hexagon<double> h(center, 5.0);
    
    ASSERT_GT(h.area(), 0.0);
}

TEST(HexagonTest, Area) {
    Point<double> center(0, 0);
    Hexagon<double> h(center, 5.0);
    double area = h.area();
    
    ASSERT_GT(area, 0.0);
}

TEST(HexagonTest, GetCenter) {
    Point<double> center(2.0, 3.0);
    Hexagon<double> h(center, 5.0);
    Point<double> retrieved_center = h.getCenter();
    
    ASSERT_DOUBLE_EQ(retrieved_center.x, 2.0);
    ASSERT_DOUBLE_EQ(retrieved_center.y, 3.0);
}

TEST(HexagonTest, Comparison) {
    Point<double> center1(0, 0);
    Point<double> center2(1, 1);
    
    Hexagon<double> h1(center1, 5.0);
    Hexagon<double> h2(center1, 5.0);
    Hexagon<double> h3(center2, 5.0);
    
    ASSERT_TRUE(h1 == h2);
    ASSERT_FALSE(h1 == h3);
}
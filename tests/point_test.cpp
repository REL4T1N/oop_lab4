#include <gtest/gtest.h>
#include "../include/point.h"
#include <sstream>

TEST(PointTest, Constructors) {
    Point<int> a;
    ASSERT_EQ(a.x, 0);
    ASSERT_EQ(a.y, 0);
    
    Point<double> b(3.5, 4.2);
    ASSERT_EQ(b.x, 3.5);
    ASSERT_EQ(b.y, 4.2);
    
    Point<double> c(b);
    ASSERT_EQ(c.x, 3.5);
    ASSERT_EQ(c.y, 4.2);
}

TEST(PointTest, Assignment) {
    Point<int> a(1, 2);
    Point<int> b;
    b = a;
    ASSERT_EQ(b.x, 1);
    ASSERT_EQ(b.y, 2);
}

TEST(PointTest, Comparison) {
    Point<double> a(1.0, 2.0);
    Point<double> b(1.0, 2.0);
    Point<double> c(1.5, 2.0);
    
    ASSERT_TRUE(a == b);
    ASSERT_FALSE(a == c);
    ASSERT_TRUE(a != c);
}

TEST(PointTest, StreamOperators) {
    Point<double> p(7.8, 9.1);
    std::stringstream ss;
    ss << p;
    ASSERT_TRUE(ss.str().find("7.8") != std::string::npos);
    ASSERT_TRUE(ss.str().find("9.1") != std::string::npos);
    
    Point<double> p2;
    std::stringstream ss2("12.34 56.78");
    ss2 >> p2;
    ASSERT_EQ(p2.x, 12.34);
    ASSERT_EQ(p2.y, 56.78);
}

TEST(PointTest, MoveSemantics) {
    Point<double> a(1.0, 2.0);
    Point<double> b(std::move(a));
    ASSERT_EQ(b.x, 1.0);
    ASSERT_EQ(b.y, 2.0);
    
    Point<double> c;
    c = std::move(b);
    ASSERT_EQ(c.x, 1.0);
    ASSERT_EQ(c.y, 2.0);
}
#include <gtest/gtest.h>
#include "../include/figure.h"
#include "../include/pentagon.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"
#include <sstream>

TEST(FigureTest, VirtualMethods) {
    Point<double> center(0, 0);
    Pentagon<double> p(center, 5.0);
    
    // Проверяем, что виртуальные методы работают
    Point<double> center_point = p.getCenter();
    double area = p.area();
    
    ASSERT_EQ(center_point.x, 0.0);
    ASSERT_EQ(center_point.y, 0.0);
    ASSERT_GT(area, 0.0);
}

TEST(FigureTest, OperatorDouble) {
    Point<double> center(0, 0);
    Pentagon<double> p(center, 5.0);
    double area1 = p.area();
    double area2 = static_cast<double>(p);
    
    ASSERT_EQ(area1, area2);
}

TEST(FigureTest, Comparison) {
    Point<double> center1(0, 0);
    Point<double> center2(1, 1);
    
    Pentagon<double> p1(center1, 5.0);
    Pentagon<double> p2(center1, 5.0);
    Pentagon<double> p3(center2, 5.0);
    
    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 == p3);
}

TEST(FigureTest, StreamOperators) {
    Point<double> center(0, 0);
    Pentagon<double> p(center, 5.0);
    std::stringstream ss;
    ss << p;
    
    // Проверяем, что вывод содержит ожидаемые данные
    std::string output = ss.str();
    ASSERT_TRUE(output.find("Pentagon") != std::string::npos);
    ASSERT_TRUE(output.find("Center") != std::string::npos);
}
#include <gtest/gtest.h>
#include "../include/array.h"
#include "../include/pentagon.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"

TEST(ArrayTest, Constructors) {
    Array<std::shared_ptr<Figure<double>>> arr;
    ASSERT_EQ(arr.getSize(), 0);
    ASSERT_TRUE(arr.isEmpty());
    
    Array<std::shared_ptr<Figure<double>>> arr2(10);
    ASSERT_EQ(arr2.getSize(), 0);
}

TEST(ArrayTest, AddRemove) {
    Array<std::shared_ptr<Figure<double>>> arr;
    Point<double> center(0, 0);
    auto pentagon = std::make_shared<Pentagon<double>>(center, 5.0);
    
    arr.addElement(pentagon);
    ASSERT_EQ(arr.getSize(), 1);
    ASSERT_FALSE(arr.isEmpty());
    
    arr.removeElement(0);
    ASSERT_EQ(arr.getSize(), 0);
    ASSERT_TRUE(arr.isEmpty());
}

TEST(ArrayTest, TotalArea) {
    Array<std::shared_ptr<Figure<double>>> arr;
    Point<double> center(0, 0);
    
    arr.addElement(std::make_shared<Pentagon<double>>(center, 5.0));
    arr.addElement(std::make_shared<Hexagon<double>>(center, 5.0));
    
    double area = arr.totalArea();
    ASSERT_GT(area, 0.0);
}

TEST(ArrayTest, Access) {
    Array<std::shared_ptr<Figure<double>>> arr;
    Point<double> center(0, 0);
    auto pentagon = std::make_shared<Pentagon<double>>(center, 5.0);
    
    arr.addElement(pentagon);
    
    auto fig = arr.getElement(0);
    ASSERT_EQ(fig, pentagon);
    
    ASSERT_THROW(arr.getElement(1), std::out_of_range);
}

TEST(ArrayTest, Clear) {
    Array<std::shared_ptr<Figure<double>>> arr;
    Point<double> center(0, 0);
    
    arr.addElement(std::make_shared<Pentagon<double>>(center, 5.0));
    arr.addElement(std::make_shared<Hexagon<double>>(center, 5.0));
    
    ASSERT_EQ(arr.getSize(), 2);
    arr.clear();
    ASSERT_EQ(arr.getSize(), 0);
    ASSERT_TRUE(arr.isEmpty());
}

TEST(ArrayTest, PrintMethods) {
    Array<std::shared_ptr<Figure<double>>> arr;
    Point<double> center(0, 0);
    
    arr.addElement(std::make_shared<Pentagon<double>>(center, 5.0));
    
    // Проверяем, что методы не падают, но не выводим в консоль
    testing::internal::CaptureStdout();  // Перехватываем вывод
    ASSERT_NO_THROW(arr.printAllFigures());
    ASSERT_NO_THROW(arr.printAllCentersAndAreas());
    testing::internal::GetCapturedStdout();  // Очищаем буфер
}
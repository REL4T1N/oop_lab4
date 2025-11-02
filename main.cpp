#include "./include/array.h"
#include "./include/pentagon.h"
#include "./include/hexagon.h"
#include "./include/octagon.h"
#include <iostream>

int main() {
    Array<std::shared_ptr<Figure<double>>> figures;
    
    std::cout << "=== LAB4 TEMPLATES DEMONSTRATION ===" << std::endl;
    
    // Добавляем фигуры каждого типа
    std::cout << "\n1. Adding figures to array..." << std::endl;
    
    Point<double> center1(0, 0);
    Point<double> center2(2, 3);
    Point<double> center3(-1, -1);
    
    // Пятиугольники
    figures.addElement(std::make_shared<Pentagon<double>>(center1, 5.0));
    figures.addElement(std::make_shared<Pentagon<double>>(center2, 3.0));
    
    // Шестиугольники
    figures.addElement(std::make_shared<Hexagon<double>>(center1, 4.0));
    figures.addElement(std::make_shared<Hexagon<double>>(center3, 6.0));
    
    // Восьмиугольники
    figures.addElement(std::make_shared<Octagon<double>>(center2, 5.0));
    figures.addElement(std::make_shared<Octagon<double>>(center3, 4.0));

    std::cout << "Added " << figures.getSize() << " figures" << std::endl;
    
    // Демонстрация работы
    std::cout << "\n2. All figures:" << std::endl;
    figures.printAllFigures();
    
    std::cout << "\n3. Centers and areas:" << std::endl;
    figures.printAllCentersAndAreas();
    
    std::cout << "\n4. Total area: " << figures.totalArea() << std::endl;
    
    // Демонстрация удаления
    std::cout << "\n5. Removing figure at index 2..." << std::endl;
    figures.removeElement(2);
    std::cout << "Remaining figures: " << figures.getSize() << std::endl;
    
    std::cout << "\n6. Final centers and areas:" << std::endl;
    figures.printAllCentersAndAreas();
    
    std::cout << "\n7. Final total area: " << figures.totalArea() << std::endl;
    
    // Демонстрация работы с разными типами (как требуется в задании)
    std::cout << "\n8. Demonstrating Array template with different types:" << std::endl;
    
    Array<Figure<double>*> raw_ptr_array;
    Array<Pentagon<double>> object_array;
    
    std::cout << "Created Array<Figure<double>*> with size: " << raw_ptr_array.getSize() << std::endl;
    std::cout << "Created Array<Pentagon<double>> with size: " << object_array.getSize() << std::endl;
    
    std::cout << "\n=== DEMONSTRATION COMPLETE ===" << std::endl;
    
    return 0;
}
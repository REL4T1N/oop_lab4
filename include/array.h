#ifndef ARRAY_H
#define ARRAY_H

#include "./figure.h"
#include <memory>
#include <stdexcept>
#include <iostream>


template<typename T>
class Array {
private:
    std::shared_ptr<T[]> _elements;
    size_t _size;
    size_t _capacity;

    void resize(size_t new_capacity);


public:
    Array();
    Array(size_t capacity);
    // explicit запрещает неявные преобразования, т.е. array<int> = 10 -- Ошибка компиляции
    // explicit Array(size_t capacity);

    
    ~Array() = default;
    // запрет на копирование (аналогично ЛР №3)
    Array(const Array&) = delete;
    Array &operator=(const Array&) = delete;


    void addElement(const T& element);
    void removeElement(size_t index);
    T getElement(size_t index) const;

    size_t getSize() const { return _size;}
    bool isEmpty() const { return _size == 0;}
    void clear() {_size = 0;}

    double totalArea() const;
    void printAllFigures() const;
    void printAllCentersAndAreas() const;
};


template<typename T>
void Array<T>::resize(size_t new_capacity) {
    if (new_capacity < _size) {
        throw std::invalid_argument("New capacity cannot be less than current size");
    }
    std::shared_ptr<T[]> new_elements(new T[new_capacity]);

    for (size_t i = 0; i < _size; i++) {
        new_elements[i] = _elements[i];
    }

    _elements = new_elements;
    _capacity = new_capacity;
}


template<typename T>
Array<T>::Array() : _elements(nullptr), _size(0), _capacity(0) {}

template<typename T>
Array<T>::Array(size_t capacity) : _size(0), _capacity(capacity) {
    _elements = std::shared_ptr<T[]>(new T[capacity]);
}


template<typename T>
void Array<T>::addElement(const T& element) {
    if (_size >= _capacity) {
        resize(_capacity == 0 ? 1 : _capacity * 2); // проверка _capacity == 0 - улучшение относительно прошлой ЛР
    }
    _elements[_size] = element;
    _size++;
}

template<typename T>
void Array<T>::removeElement(size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < _size - 1; i++) {
        _elements[i] = _elements[i + 1];
    }
    // ненужна, т.к. std::shared_ptr<T[]> делает элемент _size-1 недоступным
    // _elements[_size - 1] = nullptr;
    _size--;
}

template<typename T>
T Array<T>::getElement(size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _elements[index];
}


template<typename T>
double Array<T>::totalArea() const {
    double res = 0.0;
    for (size_t i = 0; i < _size; i++ ) {
        res += static_cast<double>(*_elements[i]);
    }
    return res;
}

template<typename T>
void Array<T>::printAllFigures() const {
    for (size_t i = 0; i < _size; i++) {
        std::cout << "Figure: " << i << " : " << *_elements[i] << std::endl;
    }
}

template<typename T>
void Array<T>::printAllCentersAndAreas() const {
    for (size_t i = 0; i < _size; i++ ) {
        std::cout << "Figure: " << i << " : ";
        std::cout << "Center: " << _elements[i]->getCenter();
        std::cout << " | Area: " << static_cast<double>(*_elements[i]) << std::endl;
    }
}


#endif
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Абстрактный базовый класс Shape
class Shape {
public:
    virtual double calculateArea() const = 0; // Чисто виртуальный метод
    virtual ~Shape() {} // Виртуальный деструктор
};

// Класс Circle (Круг)
class Circle : public Shape {
private:
    double radius;
    const double PI = 3.141592653589793;
public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return PI * radius * radius;
    }
};

// Класс Triangle (Треугольник)
class Triangle : public Shape {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}

    double calculateArea() const override {
        return 0.5 * base * height;
    }
};

// Класс Rectangle (Прямоугольник)
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const override {
        return width * height;
    }
};

// Функция для вывода информации о фигуре
void printShape(const Shape* shape) {
    cout << "Площадь: " << shape->calculateArea() << endl;
}

int main() {

    setlocale(LC_ALL, "rus");

    // Создаем вектор указателей на Shape
    vector<Shape*> shapes;

    // Добавляем различные фигуры
    shapes.push_back(new Circle(5.0));          // Круг радиусом 5
    shapes.push_back(new Triangle(4.0, 3.0));   // Треугольник с основанием 4 и высотой 3
    shapes.push_back(new Rectangle(2.0, 6.0));  // Прямоугольник 2x6
    shapes.push_back(new Circle(3.0));          // Круг радиусом 3

    // Вывод до сортировки
    cout << "До сортировки:" << endl;
    for (const auto* shape : shapes) {
        printShape(shape);
    }

    // Сортировка по площади
    sort(shapes.begin(), shapes.end(),
        [](const Shape* a, const Shape* b) {
            return a->calculateArea() < b->calculateArea();
        });

    // Вывод после сортировки
    cout << "\nПосле сортировки по площади:" << endl;
    for (const auto* shape : shapes) {
        printShape(shape);
    }

    // Очистка памяти
    for (auto* shape : shapes) {
        delete shape;
    }

    return 0;
}
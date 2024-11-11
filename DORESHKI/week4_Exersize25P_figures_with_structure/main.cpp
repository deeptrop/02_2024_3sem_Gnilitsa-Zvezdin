#include <iostream>
#include <cmath>

using namespace std;

// Структура для хранения данных круга
struct Circle {
    double radius; // Радиус круга
};

// Структура для хранения данных прямоугольника
struct Rectangle {
    double x1, y1; // Координаты первой вершины
    double x2, y2; // Координаты противоположной вершины
};

// Структура для хранения данных треугольника
struct Triangle {
    double x1, y1; // Координаты первой вершины
    double x2, y2; // Координаты второй вершины
    double x3, y3; // Координаты третьей вершины
};

// Перегруженная функция для круга
void calculate_figure(const Circle& circle) {
    // Вычисляем площадь и периметр круга
    double area = M_PI * circle.radius * circle.radius;
    double perimeter = 2 * M_PI * circle.radius;

    cout << "Фигура: Круг" << endl;
    cout << "Площадь: " << area << endl;
    cout << "Периметр: " << perimeter << endl;
}

// Перегруженная функция для прямоугольника
void calculate_figure(const Rectangle& rectangle) {
    // Вычисляем длину и ширину прямоугольника
    double width = abs(rectangle.x2 - rectangle.x1);
    double height = abs(rectangle.y2 - rectangle.y1);

    // Вычисляем площадь и периметр прямоугольника
    double area = width * height;
    double perimeter = 2 * (width + height);

    cout << "Фигура: Прямоугольник" << endl;
    cout << "Площадь: " << area << endl;
    cout << "Периметр: " << perimeter << endl;
}

// Перегруженная функция для треугольника
void calculate_figure(const Triangle& triangle) {
    // Вычисляем длины сторон треугольника
    double a = sqrt(pow(triangle.x2 - triangle.x1, 2) + pow(triangle.y2 - triangle.y1, 2));
    double b = sqrt(pow(triangle.x3 - triangle.x2, 2) + pow(triangle.y3 - triangle.y2, 2));
    double c = sqrt(pow(triangle.x1 - triangle.x3, 2) + pow(triangle.y1 - triangle.y3, 2));

    // Вычисляем периметр и полупериметр
    double perimeter = a + b + c;
    double s = perimeter / 2;

    // Вычисляем площадь по формуле Герона
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    cout << "Фигура: Треугольник" << endl;
    cout << "Площадь: " << area << endl;
    cout << "Периметр: " << perimeter << endl;
}

int main() {
    // Пример использования для круга
    Circle circle;
    circle.radius = 5; // Задаем радиус круга
    calculate_figure(circle); // Вызываем функцию для круга

    cout << endl;

    // Пример использования для прямоугольника
    Rectangle rectangle;
    rectangle.x1 = 0;
    rectangle.y1 = 0;
    rectangle.x2 = 4;
    rectangle.y2 = 3;
    calculate_figure(rectangle); // Вызываем функцию для прямоугольника

    cout << endl;

    // Пример использования для треугольника
    Triangle triangle;
    triangle.x1 = 0;
    triangle.y1 = 0;
    triangle.x2 = 4;
    triangle.y2 = 0;
    triangle.x3 = 0;
    triangle.y3 = 3;
    calculate_figure(triangle); // Вызываем функцию для треугольника

    return 0;
}

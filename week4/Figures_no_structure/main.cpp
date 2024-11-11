#include <iostream>
#include <cmath>

using namespace std;

// Эта функция принимает тип фигуры и массив параметров.
// Она вычисляет площадь и периметр фигуры и выводит результат.
void calculate_figure(int figure_type, double* parameters) {
    if (figure_type == 1) {
        // Если тип фигуры 1, то это круг.
        double radius = parameters[0]; // Радиус круга.

        double area = M_PI * radius * radius; // Площадь круга.
        double perimeter = 2 * M_PI * radius; // Периметр (длина окружности).

        cout << "Фигура: Круг" << endl;
        cout << "Площадь: " << area << endl;
        cout << "Периметр: " << perimeter << endl;

    } else if (figure_type == 2) {
        // Если тип фигуры 2, то это прямоугольник.
        // Параметры: x1, y1, x2, y2 (координаты двух противоположных вершин).
        double x1 = parameters[0];
        double y1 = parameters[1];
        double x2 = parameters[2];
        double y2 = parameters[3];

        // Вычисляем длину и ширину прямоугольника.
        double width = abs(x2 - x1);
        double height = abs(y2 - y1);

        double area = width * height; // Площадь прямоугольника.
        double perimeter = 2 * (width + height); // Периметр прямоугольника.

        cout << "Фигура: Прямоугольник" << endl;
        cout << "Площадь: " << area << endl;
        cout << "Периметр: " << perimeter << endl;

    } else if (figure_type == 3) {
        // Если тип фигуры 3, то это треугольник.
        // Параметры: x1, y1, x2, y2, x3, y3 (координаты трех вершин).
        double x1 = parameters[0];
        double y1 = parameters[1];
        double x2 = parameters[2];
        double y2 = parameters[3];
        double x3 = parameters[4];
        double y3 = parameters[5];

        // Вычисляем длины сторон треугольника.
        double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

        double perimeter = a + b + c; // Периметр треугольника.
        double s = perimeter / 2; // Полупериметр для формулы Герона.

        // Вычисляем площадь по формуле Герона.
        double area = sqrt(s * (s - a) * (s - b) * (s - c));

        cout << "Фигура: Треугольник" << endl;
        cout << "Площадь: " << area << endl;
        cout << "Периметр: " << perimeter << endl;

    } else {
        // Если тип фигуры не распознан.
        cout << "Неизвестный тип фигуры." << endl;
    }
}

int main() {
    // Пример для круга с радиусом 5
    double circle_params[] = {5}; // Радиус
    calculate_figure(1, circle_params);

    cout << endl;

    // Пример для прямоугольника с вершинами (0,0) и (4,3)
    double rectangle_params[] = {0, 0, 4, 3}; // x1, y1, x2, y2
    calculate_figure(2, rectangle_params);

    cout << endl;

    // Пример для треугольника с вершинами (0,0), (4,0), (0,3)
    double triangle_params[] = {0, 0, 4, 0, 0, 3}; // x1, y1, x2, y2, x3, y3
    calculate_figure(3, triangle_params);

    return 0;
}

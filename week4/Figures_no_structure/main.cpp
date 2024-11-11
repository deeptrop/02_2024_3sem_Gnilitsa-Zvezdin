#include <iostream>
#include <cmath>

using namespace std;

void calculate_figure(int figure_type, double* parameters) {
    if (figure_type == 1) {
        // Если тип фигуры 1, то это круг
        double radius = parameters[0]; 

        double area = M_PI * radius * radius; 
        double perimeter = 2 * M_PI * radius; 

        cout << "Фигура: Круг" << endl;
        cout << "Площадь: " << area << endl;
        cout << "Периметр: " << perimeter << endl;

    } else if (figure_type == 2) {
        // Если тип фигуры 2, то это прямоугольник
        
        double x1 = parameters[0];
        double y1 = parameters[1];
        double x2 = parameters[2];
        double y2 = parameters[3];

        
        double width = abs(x2 - x1);
        double height = abs(y2 - y1);

        double area = width * height; 
        double perimeter = 2 * (width + height); 

        cout << "Фигура: Прямоугольник" << endl;
        cout << "Площадь: " << area << endl;
        cout << "Периметр: " << perimeter << endl;

    } else if (figure_type == 3) {
        // Если тип фигуры 3, то это треугольник.
        double x1 = parameters[0];
        double y1 = parameters[1];
        double x2 = parameters[2];
        double y2 = parameters[3];
        double x3 = parameters[4];
        double y3 = parameters[5];

     
        double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

        double perimeter = a + b + c; 
        double s = perimeter / 2; 


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
 
    double circle_params[] = {5}; 
    calculate_figure(1, circle_params);

    cout << endl;


    double rectangle_params[] = {0, 0, 4, 3}; 
    calculate_figure(2, rectangle_params);

    cout << endl;

    double triangle_params[] = {0, 0, 4, 0, 0, 3}; // x1, y1, x2, y2, x3, y3
    calculate_figure(3, triangle_params);

    return 0;
}

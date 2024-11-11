#include <iostream>
#include <cmath>

using namespace std;

struct Circle {
    double radius; 
};

struct Rectangle {
    double x1, y1; 
    double x2, y2; 
};

struct Triangle {
    double x1, y1; 
    double x2, y2; 
    double x3, y3; 
};

//  функция для круга
void calculate_figure(const Circle& circle) {
    
    double area = M_PI * circle.radius * circle.radius;
    double perimeter = 2 * M_PI * circle.radius;

    cout << "Фигура: Круг" << endl;
    cout << "Площадь: " << area << endl;
    cout << "Периметр: " << perimeter << endl;
}

//  функция для прямоугольника
void calculate_figure(const Rectangle& rectangle) {
   
    double width = abs(rectangle.x2 - rectangle.x1);
    double height = abs(rectangle.y2 - rectangle.y1);

    double area = width * height;
    double perimeter = 2 * (width + height);

    cout << "Фигура: Прямоугольник" << endl;
    cout << "Площадь: " << area << endl;
    cout << "Периметр: " << perimeter << endl;
}

//  функция для треугольника
void calculate_figure(const Triangle& triangle) {

    double a = sqrt(pow(triangle.x2 - triangle.x1, 2) + pow(triangle.y2 - triangle.y1, 2));
    double b = sqrt(pow(triangle.x3 - triangle.x2, 2) + pow(triangle.y3 - triangle.y2, 2));
    double c = sqrt(pow(triangle.x1 - triangle.x3, 2) + pow(triangle.y1 - triangle.y3, 2));


    double perimeter = a + b + c;
    double s = perimeter / 2;

    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    cout << "Фигура: Треугольник" << endl;
    cout << "Площадь: " << area << endl;
    cout << "Периметр: " << perimeter << endl;
}

int main() {
   
    Circle circle;
    circle.radius = 5; 
    calculate_figure(circle); 

    cout << endl;

  
    Rectangle rectangle;
    rectangle.x1 = 0;
    rectangle.y1 = 0;
    rectangle.x2 = 4;
    rectangle.y2 = 3;
    calculate_figure(rectangle); 

    cout << endl;

  
    Triangle triangle;
    triangle.x1 = 0;
    triangle.y1 = 0;
    triangle.x2 = 4;
    triangle.y2 = 0;
    triangle.x3 = 0;
    triangle.y3 = 3;
    calculate_figure(triangle); 

    return 0;
}


#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

// Функция для вычисления интеграла методом трапеций
double integrate(double(*f)(double), double a, double b, int n)
{
    double dx = (b - a) / n; // Ширина подынтервала
    double integral = 0.5 * (f(a) + f(b)); // Начальная сумма

    for (int i = 1; i < n; ++i) {
        integral += f(a + i * dx); // Суммируем значения на подынтервалах
    }

    integral *= dx; // Умножаем на ширину подынтервала
    return integral;
}

// Пример функции для интегрирования
double exampleFunction(double x)
{
    return 3*x * x * x; // y = 3x^3
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите нижний предел интегрирования: ";
    double a;  // Нижний предел интегрирования
    cin >> a;
    cout << "Введите верхний предел интегрирования: ";
    double b; // Верхний предел интегрирования
    cin >> b;

    int n = 1000;    // Количество подынтервалов

    double result = integrate(exampleFunction, a, b, n);
    cout << "Интеграл от функции 3x^3 на отрезке [" << a << ", " << b << "] равен: " << result << endl;

    return 0;
}
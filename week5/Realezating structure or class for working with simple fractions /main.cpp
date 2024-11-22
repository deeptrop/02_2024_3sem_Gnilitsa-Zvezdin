// main.cpp

#include <iostream>
#include "fraction.h"

using namespace std;
using namespace FractionNamespace;

int main() {

    Fraction f1(1, 2); // 1/2
    Fraction f2(3, 4); // 3/4

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;


    Fraction sum = f1 + f2;
    cout << "f1 + f2 = " << sum << endl;

    Fraction diff = f1 - f2;
    cout << "f1 - f2 = " << diff << endl;


    Fraction prod = f1 * f2;
    cout << "f1 * f2 = " << prod << endl;

 
    Fraction quot = f1 / f2;
    cout << "f1 / f2 = " << quot << endl;

    // Проверка
    cout << "f1 == f2: " << (f1 == f2 ? "true" : "false") << endl;
    cout << "f1 != f2: " << (f1 != f2 ? "true" : "false") << endl;
    cout << "f1 < f2: " << (f1 < f2 ? "true" : "false") << endl;
    cout << "f1 <= f2: " << (f1 <= f2 ? "true" : "false") << endl;
    cout << "f1 > f2: " << (f1 > f2 ? "true" : "false") << endl;
    cout << "f1 >= f2: " << (f1 >= f2 ? "true" : "false") << endl;

    //  инкремент и декремент
    cout << "f1 до инкремента: " << f1 << endl;
    cout << "++f1: " << ++f1 << endl;
    cout << "f1 после префиксного инкремента: " << f1 << endl;
    cout << "f1++: " << f1++ << endl;
    cout << "f1 после постфиксного инкремента: " << f1 << endl;

    cout << "f2 до декремента: " << f2 << endl;
    cout << "--f2: " << --f2 << endl;
    cout << "f2 после префиксного декремента: " << f2 << endl;
    cout << "f2--: " << f2-- << endl;
    cout << "f2 после постфиксного декремента: " << f2 << endl;

    // Приведение к double
    double value = static_cast<double>(f1);
    cout << "f1 как double: " << value << endl;

    Fraction userFraction;
    cout << "Введите дробь в формате числитель/знаменатель: ";
    cin >> userFraction;
    if (cin) {
        cout << "Вы ввели дробь: " << userFraction << endl;
    } else {
        cout << "Некорректный ввод." << endl;
    }

    return 0;
}

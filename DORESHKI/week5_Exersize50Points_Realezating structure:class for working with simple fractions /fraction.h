// fraction.h

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

namespace FractionNamespace {

    // Класс для работы с обыкновенными дробями
    class Fraction {
    private:
        int numerator;   // Числитель дроби
        int denominator; // Знаменатель дроби

        // Вспомогательная функция для нахождения НОД (наибольшего общего делителя)
        int gcd(int a, int b) const;

        // Вспомогательная функция для сокращения дроби
        void reduce();

    public:
        // Конструктор по умолчанию (дробь 0/1)
        Fraction();

        // Конструктор с параметрами (числитель и знаменатель)
        Fraction(int num, int denom);

        // Конструктор копирования
        Fraction(const Fraction& other);

        // Конструктор перемещения
        Fraction(Fraction&& other);

        // Оператор присваивания копированием
        Fraction& operator=(const Fraction& other);

        // Оператор присваивания перемещением
        Fraction& operator=(Fraction&& other);

        // Арифметические операторы
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;

        // Операторы сравнения
        bool operator==(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;

        // Унарный минус
        Fraction operator-() const;

        // Операторы инкремента и декремента
        Fraction& operator++();    // Префиксный инкремент
        Fraction operator++(int);  // Постфиксный инкремент
        Fraction& operator--();    // Префиксный декремент
        Fraction operator--(int);  // Постфиксный декремент

        // Операторы приведения типов
        operator double() const;

        // Доступ к числителю и знаменателю
        int getNumerator() const;
        int getDenominator() const;

        // Перегрузка операторов ввода и вывода
        friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& is, Fraction& fraction);
    };

} // namespace FractionNamespace

#endif // FRACTION_H

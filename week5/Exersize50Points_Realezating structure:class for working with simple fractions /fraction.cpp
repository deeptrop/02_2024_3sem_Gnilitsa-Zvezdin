// fraction.cpp

#include "fraction.h"
#include <iostream>
#include <stdexcept>

namespace FractionNamespace {

    // Конструктор по умолчанию (дробь 0/1)
    Fraction::Fraction() : numerator(0), denominator(1) {}

    // Конструктор с параметрами (числитель и знаменатель)
    Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw std::invalid_argument("Знаменатель не может быть равен нулю.");
        }
        reduce();
    }

    // Конструктор копирования
    Fraction::Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}

    // Конструктор перемещения
    Fraction::Fraction(Fraction&& other) : numerator(other.numerator), denominator(other.denominator) {
        other.numerator = 0;
        other.denominator = 1;
    }

    // Оператор присваивания копированием
    Fraction& Fraction::operator=(const Fraction& other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

    // Оператор присваивания перемещением
    Fraction& Fraction::operator=(Fraction&& other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
            other.numerator = 0;
            other.denominator = 1;
        }
        return *this;
    }

    // Вспомогательная функция для нахождения НОД (алгоритм Евклида)
    int Fraction::gcd(int a, int b) const {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    // Вспомогательная функция для сокращения дроби
    void Fraction::reduce() {
        int gcdValue = gcd(abs(numerator), abs(denominator));
        numerator /= gcdValue;
        denominator /= gcdValue;

        // Обеспечиваем положительный знаменатель
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Арифметические операторы
    Fraction Fraction::operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction Fraction::operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction Fraction::operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction Fraction::operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Деление на ноль.");
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    // Операторы сравнения
    bool Fraction::operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool Fraction::operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool Fraction::operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool Fraction::operator<=(const Fraction& other) const {
        return *this < other || *this == other;
    }

    bool Fraction::operator>(const Fraction& other) const {
        return !(*this <= other);
    }

    bool Fraction::operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    // Унарный минус
    Fraction Fraction::operator-() const {
        return Fraction(-numerator, denominator);
    }

    // Операторы инкремента и декремента
    Fraction& Fraction::operator++() {
        numerator += denominator;
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction temp(*this);
        numerator += denominator;
        return temp;
    }

    Fraction& Fraction::operator--() {
        numerator -= denominator;
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp(*this);
        numerator -= denominator;
        return temp;
    }

    // Оператор приведения к double
    Fraction::operator double() const {
        return static_cast<double>(numerator) / denominator;
    }

    // Доступ к числителю и знаменателю
    int Fraction::getNumerator() const {
        return numerator;
    }

    int Fraction::getDenominator() const {
        return denominator;
    }

    // Перегрузка оператора вывода
    std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }

    // Перегрузка оператора ввода
    std::istream& operator>>(std::istream& is, Fraction& fraction) {
        int num, denom;
        char slash;
        is >> num >> slash >> denom;
        if (slash != '/') {
            is.setstate(std::ios::failbit);
            return is;
        }
        if (denom == 0) {
            is.setstate(std::ios::failbit);
            return is;
        }
        fraction = Fraction(num, denom);
        return is;
    }

} // namespace FractionNamespace

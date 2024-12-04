#ifndef TUPLE_HPP
#define TUPLE_HPP

#include <iostream>

// Это шаблон класса tuple.
// Он позволяет хранить набор данных разного типа.
// Например, кортеж может хранить int, bool, double и char.

template<typename T, typename ... argsT>
class tuple {
public:
  tuple() {} // Конструктор по умолчанию.

  // Конструктор, принимающий первый элемент и остальные через шаблоны.
  tuple(T arg0, argsT... args): first(arg0), others(args...) {}

  T first; // Это поле хранит первый элемент кортежа.
  tuple<argsT...> others; // Это поле хранит оставшуюся часть кортежа.

  // Метод для печати текущего элемента и всех остальных.
  void print(std::ostream& os) const {
    os << first << ", "; // Выводим текущий элемент.
    others.print(os); // Рекурсивно выводим остальные.
  }
};

// Базовый случай для последнего элемента кортежа.
template<typename T>
class tuple<T> {
public:
  tuple() {} // Конструктор по умолчанию.

  // Конструктор, принимающий значение для последнего элемента.
  tuple(T val): first(val) {};

  T first; // Это поле хранит последний элемент кортежа.

  // Метод печати для последнего элемента.
  void print(std::ostream& os) const {
    os << first; // Последний элемент без запятой.
  }
};

// Этот оператор нужен для вывода кортежа через std::ostream.
// Например: std::cout << my_tuple;
template<typename ... argsT>
std::ostream& operator<<(std::ostream& os, const tuple<argsT...>& t) {
  os << "("; // Открываем скобку перед выводом кортежа.
  t.print(os); // Вызываем метод печати.
  os << ")"; // Закрываем скобку после вывода.
  return os;
}

#endif // TUPLE_HPP
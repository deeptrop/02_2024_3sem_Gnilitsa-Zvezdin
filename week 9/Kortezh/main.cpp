#include <iostream>
#include "tuple.hpp"
#include "get.hpp"

int main() {
  // Создаем кортеж с элементами разного типа.
  tuple<int, bool, double, char> my_tuple(42, true, 3.14, 'x');

  // Выводим весь кортеж.
  std::cout << "Кортеж: " << my_tuple << std::endl;

  // Доступ к элементам кортежа через get<N>.
  // Выводим первый элемент.
  std::cout << "Элемент 0: " << get<0>(my_tuple) << std::endl;

  // Выводим второй элемент.
  std::cout << "Элемент 1: " << get<1>(my_tuple) << std::endl;

  // Выводим третий элемент.
  std::cout << "Элемент 2: " << get<2>(my_tuple) << std::endl;

  // Выводим четвертый элемент.
  std::cout << "Элемент 3: " << get<3>(my_tuple) << std::endl;

  return 0;
}
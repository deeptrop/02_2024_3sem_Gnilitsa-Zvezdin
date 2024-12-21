#include <iostream>
#include <iterator>
#include "list.hpp"
#include <vector>

// Этот код реализует сортировку массива методом слияния (Merge Sort).
// Алгоритм поддерживает пользовательские функции сравнения.
// Позволяет сортировать как по возрастанию, так и по убыванию.
// Сортировка работает с динамическими массивами, статическими массивами, векторами и кастомными списками.

// Это функция для сравнения по возрастанию
template <typename T>
bool less(const T& a, const T& b) {
  return a < b;
}

// Это функция для сравнения по убыванию
template <typename T>
bool greater(const T& a, const T& b) {
  return a > b;
}

// Эта функция делит массив на две части, сортирует их и сливает обратно.
// Здесь используется рекурсия.
// Параметры:
// - begin: итератор на начало массива
// - end: итератор на конец массива
// - compare: функция для сравнения элементов
template <typename Iterator, typename Comparator>
void MergeSort(Iterator begin, Iterator end, Comparator compare) {
  size_t size = std::distance(begin, end); // Это размер массива
  if (size <= 1) { // Если в массиве 0 или 1 элемент, то он уже отсортирован
    return;
  }

  Iterator mid = std::next(begin, size / 2); // Это середина массива
  // Создаем временные массивы для левой и правой частей
  std::vector<typename std::iterator_traits<Iterator>::value_type> left(begin, mid);
  std::vector<typename std::iterator_traits<Iterator>::value_type> right(mid, end);

  // Рекурсивно сортируем левую и правую части
  MergeSort(left.begin(), left.end(), compare);
  MergeSort(right.begin(), right.end(), compare);

  // Сливаем отсортированные части обратно
  auto left_it = left.begin();
  auto right_it = right.begin();

  // Здесь мы сравниваем элементы из левой и правой части
  while (left_it != left.end() && right_it != right.end()) {
    if (compare(*left_it, *right_it)) {
      *begin++ = *left_it++;
    } else {
      *begin++ = *right_it++;
    }
  }

  // Если в левой части остались элементы, добавляем их
  while (left_it != left.end()) {
    *begin++ = *left_it++;
  }

  // Если в правой части остались элементы, добавляем их
  while (right_it != right.end()) {
    *begin++ = *right_it++;
  }
}

// Это перегруженная версия MergeSort для сортировки по возрастанию
template <typename Iterator>
void MergeSort(Iterator begin, Iterator end) {
  MergeSort(begin, end, less<typename std::iterator_traits<Iterator>::value_type>);
}

int main() {
  // Сортировка статического массива
  int static_array[] = {28, 37, 21, 4, 15, 9};
  size_t static_size = 6;

  std::cout << "Статический массив до сортировки: ";
  for (int num : static_array) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // Сортируем статический массив
  MergeSort(static_array, static_array + static_size);

  std::cout << "Статический массив после сортировки: ";
  for (int num : static_array) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // Сортировка динамического массива
  int* dyn_array = new int[6]{28, 37, 21, 4, 15, 9};
  size_t dyn_size = 6;

  std::cout << "Динамический массив до сортировки: ";
  for (size_t i = 0; i < dyn_size; ++i) {
    std::cout << dyn_array[i] << " ";
  }
  std::cout << std::endl;

  // Сортируем динамический массив
  MergeSort(dyn_array, dyn_array + dyn_size);

  std::cout << "Динамический массив после сортировки: ";
  for (size_t i = 0; i < dyn_size; ++i) {
    std::cout << dyn_array[i] << " ";
  }
  std::cout << std::endl;

  delete[] dyn_array; // Освобождаем память

  // Сортировка вектора
  std::vector<int> vec = {28, 37, 21, 4, 15, 9};

  std::cout << "Вектор до сортировки: ";
  for (int num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // Сортируем вектор
  MergeSort(vec.begin(), vec.end());

  std::cout << "Вектор после сортировки: ";
  for (int num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // Сортировка кастомного списка
  list<int> my_list;
  my_list.push_back(28);
  my_list.push_back(37);
  my_list.push_back(21);
  my_list.push_back(4);
  my_list.push_back(15);
  my_list.push_back(9);

  std::cout << "Список до сортировки: ";
  my_list.print_list();

  // Сортируем кастомный список
  MergeSort(my_list.begin(), my_list.end());

  std::cout << "Список после сортировки: ";
  my_list.print_list();

  return 0;
}
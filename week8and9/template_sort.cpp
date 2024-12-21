#include <iostream>

// Этот код реализует сортировку динамического массива методом слияния (Merge Sort).
// Алгоритм поддерживает кастомные функции сравнения и позволяет сортировать
// как в порядке возрастания, убывания, так и с пользовательскими функциями сравнения.

// Функция для сравнения элементов по возрастанию
template <typename T>
bool less(const T& a, const T& b) {
  return a < b;
}

// Функция для сравнения элементов по убыванию
template <typename T>
bool greater(const T& a, const T& b) {
  return a > b;
}

// Эта функция реализует слияние двух отсортированных массивов
// Параметры:
// - left, right: указатели на начало левого и правого массива
// - size_left, size_right: размеры этих массивов
// - array: целевой массив для результата слияния
// - compare: функция сравнения
template <typename T, typename Comparator>
void Merge(T* left, int size_left, T* right, int size_right, T* array, Comparator compare) {
  int index_left = 0;  // Индекс текущего элемента в левом массиве
  int index_right = 0; // Индекс текущего элемента в правом массиве
  int index_array = 0; // Индекс текущей позиции в итоговом массиве

  // Основной цикл слияния
  while (index_left < size_left && index_right < size_right) {
    if (compare(left[index_left], right[index_right])) {
      array[index_array++] = left[index_left++];
    } else {
      array[index_array++] = right[index_right++];
    }
  }

  // Добавляем оставшиеся элементы из левого массива
  while (index_left < size_left) {
    array[index_array++] = left[index_left++];
  }

  // Добавляем оставшиеся элементы из правого массива
  while (index_right < size_right) {
    array[index_array++] = right[index_right++];
  }
}

// Эта функция рекурсивно делит массив на две части и сортирует их
// Параметры:
// - array: указатель на начало массива
// - size: размер массива
// - compare: функция сравнения
template <typename T, typename Comparator>
void MergeSort(T* array, int size, Comparator compare) {
  if (size <= 1) {
    return; // Базовый случай: массив размером 1 уже отсортирован
  }

  // Вычисляем середину массива
  int mid = (size + 1) / 2;

  // Создаем временные массивы для левой и правой части
  T* left = new T[mid];
  T* right = new T[size - mid];

  // Копируем элементы в левую и правую части
  for (int i = 0; i < mid; i++) {
    left[i] = array[i];
  }
  for (int i = mid; i < size; i++) {
    right[i - mid] = array[i];
  }

  // Рекурсивно сортируем левую и правую части
  MergeSort(left, mid, compare);
  MergeSort(right, size - mid, compare);

  // Сливаем две отсортированные части в исходный массив
  Merge(left, mid, right, size - mid, array, compare);

  // Освобождаем память для временных массивов
  delete[] left;
  delete[] right;
}

// Перегрузка MergeSort для сортировки по умолчанию (возрастание)
template <typename T>
void MergeSort(T* array, int size) {
  MergeSort(array, size, less<T>);
}

int main() {
  // Пример с динамическим массивом
  int* dyn_array = new int[6]{28, 37, 21, 4, 15, 9}; // Исходный массив
  int dyn_size = 6; // Размер массива

  // Вывод массива до сортировки
  std::cout << "Динамический массив до сортировки: ";
  for (int i = 0; i < dyn_size; i++) {
    std::cout << dyn_array[i] << " ";
  }
  std::cout << std::endl;

  // Сортировка по возрастанию
  MergeSort(dyn_array, dyn_size, less<int>);
  std::cout << "Динамический массив после сортировки по возрастанию: ";
  for (int i = 0; i < dyn_size; i++) {
    std::cout << dyn_array[i] << " ";
  }
  std::cout << std::endl;

  // Сортировка по убыванию
  MergeSort(dyn_array, dyn_size, greater<int>);
  std::cout << "Динамический массив после сортировки по убыванию: ";
  for (int i = 0; i < dyn_size; i++) {
    std::cout << dyn_array[i] << " ";
  }
  std::cout << std::endl;

  // Освобождаем память для динамического массива
  delete[] dyn_array;

  return 0;
}
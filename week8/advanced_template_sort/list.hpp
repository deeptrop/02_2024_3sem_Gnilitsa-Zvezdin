#include <iostream>

// Код нашего списка, для того, чтобы показать, что наша сортировка может с ним работать

// Эта структура данных необходима для работы со списком в целом
template <typename T>
struct list {
  // Это структура для хранения одного элемента списка
  struct list_item {
    T data;       // Это поле хранит данные типа T
    list_item* next;  // Это поле хранит указатель на следующий элемент списка

    // Конструктор для инициализации элемента списка
    list_item(const T& value) : data(value), next(nullptr) {}
  };

  list_item* first;  // Это указатель на первый элемент списка
  list_item* last;   // Это указатель на последний элемент списка
  size_t count;      // Это поле хранит количество элементов в списке

  // Конструктор инициализирует пустой список
  list() : first(nullptr), last(nullptr), count(0) {}

  // Проверка, пуст ли список
  bool is_empty() const {
    return count == 0;
  }

  // Добавление элемента в конец списка
  void push_back(const T& value) {
    list_item* new_item = new list_item(value);  // Создаем новый элемент
    if (is_empty()) {  // Если список пустой
      first = last = new_item;  // Новый элемент будет первым и последним
    } else {
      last->next = new_item;  // Добавляем новый элемент в конец списка
      last = new_item;  // Новый элемент теперь последний
    }
    ++count;  // Увеличиваем количество элементов в списке
  }

  // Печать всех элементов списка
  void print_list() const {
    list_item* current = first;
    while (current) {  // Пока не дошли до конца списка
      std::cout << current->data << " ";  // Печатаем данные текущего элемента
      current = current->next;  // Переходим к следующему элементу
    }
    std::cout << std::endl;
  }

  // Деструктор для освобождения памяти
  ~list() {
    list_item* current = first;
    while (current) {  // Пока не дошли до конца списка
      list_item* next = current->next;
      delete current;  // Удаляем текущий элемент
      current = next;  // Переходим к следующему элементу
    }
  }

  // Итератор — это объект, который позволяет нам обходить элементы списка.
  // С помощью итераторов мы можем пройти по всем элементам.

  // В следующем задании, когда нужно будет доделать сортировку, итераторы помогут
  // работать с нашим списком.

  struct iterator {
    using value_type = T;              // Тип данных, хранящийся в списке
    using reference = T&;              // Тип ссылки на данные
    using pointer = T*;                // Тип указателя на данные
    using difference_type = int; // Тип для указания расстояния между итераторами
    using iterator_category = std::forward_iterator_tag; // Категория итератора

    list_item* current;  // Указатель на текущий элемент

    // Конструктор итератора
    iterator(list_item* value) : current(value) {}

    // Разыменовывание итератора (получение данных из текущего элемента)
    reference operator*() { return current->data; }

    // Оператор инкремента (переход к следующему элементу)
    iterator& operator++() {
      current = current->next;
      return *this;
    }

    // Постфиксный инкремент
    iterator operator++(int) {
      iterator temp = *this;
      ++(*this); // Использует префиксный инкремент
      return temp;
    }

    // Оператор сравнения на равенство (сравниваем текущие элементы)
    bool operator==(const iterator& other) const {
      return current == other.current;
    }

    // Оператор сравнения на неравенство (сравниваем текущие элементы)
    bool operator!=(const iterator& other) const {
      return current != other.current;
    }
  };

  // Функция, которая возвращает итератор на первый элемент списка
  iterator begin() { return iterator(first); }

  // Функция, которая возвращает итератор на конец - "пустой" элемент после последнего
  iterator end() { return iterator(nullptr); }
};
#include <iostream>

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
    list_item* current;  // Указатель на текущий элемент

    // Конструктор итератора
    iterator(list_item* value) : current(value) {}

    // Разыменовывание итератора (получение данных из текущего элемента)
    T& operator*() { return current->data; }

    // Оператор инкремента (переход к следующему элементу)
    iterator& operator++() {
      current = current->next;
      return *this;
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

int main() {
  list<int> l;
  std::cout << "Список пуст? " << l.is_empty() << std::endl;  // Проверка, пуст ли список

  // Добавляем элементы в список
  l.push_back(28);
  l.push_back(37);
  l.push_back(21);
  l.push_back(4);

  // Печатаем все элементы списка
  std::cout << "Элементы списка: ";
  l.print_list();

  // Проверка снова, пуст ли список
  std::cout << "Список пуст? " << l.is_empty() << std::endl;

  // Теперь показываем, как использовать итератор
  // Итератор позволяет нам пройти по всем элементам списка, не зная его внутренней структуры
  std::cout << "Итераторный обход списка: ";
  for (auto it = l.begin(); it != l.end(); ++it) {  // Итератор начинает с первого элемента
    std::cout << *it << " ";  // Разыменовываем итератор, получаем данные элемента
  }
  std::cout << std::endl;

  return 0;
}

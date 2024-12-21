// list.cpp

#include "list.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Конструктор для элемента списка
list_item::list_item(int _data) : data(_data), next(nullptr), previous(nullptr) {}

// Конструктор по умолчанию для списка
list::list() : first(nullptr), last(nullptr), current(nullptr) {}

// Деструктор списка
list::~list() {
    clear(); // Очищаем список при уничтожении объекта
}

// Метод для очистки списка и освобождения памяти
void list::clear() {
    list_item* p = first;
    while (p != nullptr) {
        list_item* next = p->next;
        delete p; // Удаляем каждый элемент
        p = next;
    }
    first = last = current = nullptr;
}

// Геттер для данных текущего элемента
int list::get_current_data() const {
    if (current != nullptr) {
        return current->data;
    }
    throw runtime_error("Текущий элемент не установлен.");
}

// Метод для установки текущего элемента на первый
void list::set_current_to_first() {
    current = first;
}

// Метод для установки текущего элемента на последний
void list::set_current_to_last() {
    current = last;
}

// Метод для установки текущего элемента по значению данных
bool list::set_current_by_value(int value) {
    list_item* temp = first;
    while (temp != nullptr) {
        if (temp->data == value) {
            current = temp;
            return true;
        }
        temp = temp->next;
    }
    return false; // Элемент с таким значением не найден
}

// Геттер для данных первого элемента
int list::get_first_data() const {
    if (first != nullptr) {
        return first->data;
    }
    throw runtime_error("Список пуст.");
}

// Сеттер для данных первого элемента
void list::set_first_data(int value) {
    if (first != nullptr) {
        first->data = value;
    } else {
        throw runtime_error("Список пуст. Нельзя установить данные первого элемента.");
    }
}

// Конструктор копирования
list::list(const list& other) : first(nullptr), last(nullptr), current(nullptr) {
    // Копируем элементы из другого списка
    list_item* p = other.first;
    while (p != nullptr) {
        push_back(p->data);
        if (p == other.current) {
            current = last; // Устанавливаем текущий элемент
        }
        p = p->next;
    }
}

// Конструктор перемещения
list::list(list&& other) : first(other.first), last(other.last), current(other.current) {
    // Обнуляем указатели в исходном объекте
    other.first = nullptr;
    other.last = nullptr;
    other.current = nullptr;
}

// Оператор присваивания копированием
list& list::operator=(const list& other) {
    if (this != &other) {
        clear(); // Очищаем текущий список
        // Копируем элементы из другого списка
        list_item* p = other.first;
        while (p != nullptr) {
            push_back(p->data);
            if (p == other.current) {
                current = last;
            }
            p = p->next;
        }
    }
    return *this;
}

// Оператор присваивания перемещением
list& list::operator=(list&& other) {
    if (this != &other) {
        clear(); // Очищаем текущий список
        // Перемещаем данные из другого списка
        first = other.first;
        last = other.last;
        current = other.current;
        other.first = nullptr;
        other.last = nullptr;
        other.current = nullptr;
    }
    return *this;
}

// Проверяет, пуст ли список
bool list::is_empty() const {
    return first == nullptr;
}

// Добавляет новый элемент в конец списка
void list::push_back(int data) {
    list_item* p_tmp = new list_item(data);
    if (is_empty()) {
        first = last = current = p_tmp;
    } else {
        p_tmp->previous = last;
        last->next = p_tmp;
        last = p_tmp;
    }
}

// Добавляет новый элемент в начало списка
void list::push_front(int data) {
    list_item* p_tmp = new list_item(data);
    if (is_empty()) {
        first = last = current = p_tmp;
    } else {
        p_tmp->next = first;
        first->previous = p_tmp;
        first = p_tmp;
    }
}

// Вставляет новый элемент в текущую позицию
void list::insert_at_current(int data) {
    if (current == nullptr) {
        push_back(data);
        return;
    }
    list_item* p_tmp = new list_item(data);
    p_tmp->next = current;
    p_tmp->previous = current->previous;
    if (current->previous != nullptr) {
        current->previous->next = p_tmp;
    } else {
        first = p_tmp;
    }
    current->previous = p_tmp;
    current = p_tmp;
}

// Перемещает текущий указатель на следующий элемент
void list::move_current_right() {
    if (current != nullptr && current->next != nullptr) {
        current = current->next;
    } else {
        cout << "Невозможно переместиться вправо, текущий элемент последний или не установлен." << endl;
    }
}

// Перемещает текущий указатель на предыдущий элемент
void list::move_current_left() {
    if (current != nullptr && current->previous != nullptr) {
        current = current->previous;
    } else {
        cout << "Невозможно переместиться влево, текущий элемент первый или не установлен." << endl;
    }
}

// Удаляет первый элемент списка
void list::delete_first() {
    if (is_empty()) {
        cout << "Список пуст, нечего удалять." << endl;
        return;
    }
    list_item* to_delete = first;
    if (first == last) {
        first = last = current = nullptr;
    } else {
        first = first->next;
        first->previous = nullptr;
        if (current == to_delete) {
            current = first;
        }
    }
    delete to_delete;
}

// Удаляет последний элемент списка
void list::delete_last() {
    if (is_empty()) {
        cout << "Список пуст, нечего удалять." << endl;
        return;
    }
    list_item* to_delete = last;
    if (first == last) {
        first = last = current = nullptr;
    } else {
        last = last->previous;
        last->next = nullptr;
        if (current == to_delete) {
            current = last;
        }
    }
    delete to_delete;
}

// Удаляет текущий элемент списка
void list::delete_current() {
    if (current == nullptr) {
        cout << "Текущий элемент не установлен, нечего удалять." << endl;
        return;
    }
    list_item* to_delete = current;
    if (first == last) {
        first = last = current = nullptr;
    } else if (to_delete == first) {
        first = to_delete->next;
        first->previous = nullptr;
        current = first;
    } else if (to_delete == last) {
        last = to_delete->previous;
        last->next = nullptr;
        current = last;
    } else {
        to_delete->previous->next = to_delete->next;
        to_delete->next->previous = to_delete->previous;
        current = to_delete->next;
    }
    delete to_delete;
}

// Печатает список от начала до конца
void list::print_list() const {
    list_item* p_tmp = first;
    cout << "Список от начала до конца:" << endl;
    while (p_tmp != nullptr) {
        cout << p_tmp->data << " ";
        p_tmp = p_tmp->next;
    }
    cout << endl;
}

// Печатает список от конца до начала
void list::print_list_reverse() const {
    list_item* p_tmp = last;
    cout << "Список от конца до начала:" << endl;
    while (p_tmp != nullptr) {
        cout << p_tmp->data << " ";
        p_tmp = p_tmp->previous;
    }
    cout << endl;
}

// Разбивает список на два по текущему элементу
void list::split_at_current(list& new_list) {
    if (current == nullptr) {
        cout << "Текущий элемент не установлен, невозможно разделить список." << endl;
        return;
    }
    new_list.clear();
    new_list.first = current;
    new_list.last = last;
    new_list.current = current;
    if (current->previous != nullptr) {
        current->previous->next = nullptr;
        last = current->previous;
        current->previous = nullptr;
    } else {
        first = last = current = nullptr;
    }
}

// Перегруженный оператор вывода списка
std::ostream& operator<<(std::ostream& os, const list& lst) {
    list_item* p_tmp = lst.first;
    while (p_tmp != nullptr) {
        os << p_tmp->data << " ";
        p_tmp = p_tmp->next;
    }
    return os;
}

// Перегруженный оператор ввода списка
std::istream& operator>>(std::istream& is, list& lst) {
    int value;
    while (is >> value) {
        lst.push_back(value);
    }
    return is;
}

// Оператор конкатенации списков (копирование)
list list::operator+(const list& other) const {
    list result(*this); // Копируем текущий список
    list_item* p = other.first;
    while (p != nullptr) {
        result.push_back(p->data);
        p = p->next;
    }
    return result;
}

// Оператор конкатенации списков (перемещение временных объектов)
list list::operator+(list&& other) {
    list result(std::move(*this)); // Перемещаем текущий список
    if (!other.is_empty()) {
        if (result.is_empty()) {
            result.first = other.first;
            result.last = other.last;
        } else {
            result.last->next = other.first;
            other.first->previous = result.last;
            result.last = other.last;
        }
        other.first = other.last = other.current = nullptr;
    }
    return result;
}


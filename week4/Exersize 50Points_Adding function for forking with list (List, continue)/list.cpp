// list.cpp

#include "list.h"
#include <iostream>

using namespace std;

// Реализация конструктора для элемента списка
list_item::list_item(int _data) : data(_data), next(nullptr), previous(nullptr) {}

// Конструктор для инициализации пустого списка
list::list() : first(nullptr), last(nullptr), current(nullptr) {}

// Деструктор для очистки списка и освобождения памяти
list::~list() {
    // Проходим по всему списку и удаляем каждый элемент
    list_item* p = first;
    while (p != nullptr) {
        list_item* next = p->next; // Сохраняем указатель на следующий элемент
        delete p; // Удаляем текущий элемент
        p = next; // Переходим к следующему элементу
    }
}

// Проверяет, пуст ли список
bool list::is_empty() {
    return first == nullptr;
}

// Добавляет новый элемент в конец списка
void list::push_back(int data) {
    // Создаем новый элемент
    list_item* p_tmp = new list_item(data);

    if (is_empty()) {
        // Если список пуст, новый элемент становится первым, последним и текущим
        first = p_tmp;
        last = p_tmp;
        current = p_tmp;
        return;
    }

    // Связываем новый элемент с текущим последним
    p_tmp->previous = last;
    last->next = p_tmp;
    last = p_tmp; // Обновляем указатель на последний элемент
}

// Добавляет новый элемент в начало списка
void list::push_front(int data) {
    // Создаем новый элемент
    list_item* p_tmp = new list_item(data);

    if (is_empty()) {
        // Если список пуст, новый элемент становится первым, последним и текущим
        first = p_tmp;
        last = p_tmp;
        current = p_tmp;
        return;
    }

    // Связываем новый элемент с текущим первым
    p_tmp->next = first;
    first->previous = p_tmp;
    first = p_tmp; // Обновляем указатель на первый элемент
}

// Вставляет новый элемент в текущую позицию
void list::insert_at_current(int data) {
    if (current == nullptr) {
        // Если текущий элемент не установлен, добавляем в конец
        push_back(data);
        return;
    }

    // Создаем новый элемент
    list_item* p_tmp = new list_item(data);

    // Вставляем новый элемент перед текущим
    p_tmp->next = current;
    p_tmp->previous = current->previous;

    if (current->previous != nullptr) {
        current->previous->next = p_tmp;
    } else {
        // Если текущий элемент был первым, обновляем указатель на первый элемент
        first = p_tmp;
    }
    current->previous = p_tmp;

    // Делаем новый элемент текущим
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
        // Если в списке только один элемент
        first = nullptr;
        last = nullptr;
        current = nullptr;
    } else {
        // Перемещаем первый элемент на следующий
        first = first->next;
        first->previous = nullptr;

        if (current == to_delete) {
            current = first;
        }
    }

    delete to_delete; // Удаляем элемент
}

// Удаляет последний элемент списка
void list::delete_last() {
    if (is_empty()) {
        cout << "Список пуст, нечего удалять." << endl;
        return;
    }

    list_item* to_delete = last;

    if (first == last) {
        // Если в списке только один элемент
        first = nullptr;
        last = nullptr;
        current = nullptr;
    } else {
        // Перемещаем последний элемент на предыдущий
        last = last->previous;
        last->next = nullptr;

        if (current == to_delete) {
            current = last;
        }
    }

    delete to_delete; // Удаляем элемент
}

// Удаляет текущий элемент списка
void list::delete_current() {
    if (current == nullptr) {
        cout << "Текущий элемент не установлен, нечего удалять." << endl;
        return;
    }

    list_item* to_delete = current;

    if (first == last) {
        // Если в списке только один элемент
        first = nullptr;
        last = nullptr;
        current = nullptr;
    } else if (to_delete == first) {
        // Если удаляем первый элемент
        first = to_delete->next;
        first->previous = nullptr;
        current = first;
    } else if (to_delete == last) {
        // Если удаляем последний элемент
        last = to_delete->previous;
        last->next = nullptr;
        current = last;
    } else {
        // Удаляем элемент из середины списка
        to_delete->previous->next = to_delete->next;
        to_delete->next->previous = to_delete->previous;
        current = to_delete->next; // Перемещаем текущий на следующий элемент
    }

    delete to_delete; // Удаляем элемент
}

// Печатает список от начала до конца
void list::print_list() {
    list_item* p_tmp = first;
    cout << "Список от начала до конца:" << endl;
    while (p_tmp != nullptr) {
        cout << p_tmp->data << " ";
        p_tmp = p_tmp->next;
    }
    cout << endl;
}

// Печатает список от конца до начала
void list::print_list_reverse() {
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

    // Новый список будет содержать элементы от current до last
    new_list.first = current;
    new_list.last = last;
    new_list.current = current;

    // Корректируем связи в исходном списке
    if (current->previous != nullptr) {
        current->previous->next = nullptr;
        last = current->previous;
    } else {
        // Если current был первым элементом, исходный список станет пустым
        first = nullptr;
        last = nullptr;
        current = nullptr;
        return;
    }

    current->previous = nullptr;

    // В исходном списке текущий элемент обновляем
    current = last;
}

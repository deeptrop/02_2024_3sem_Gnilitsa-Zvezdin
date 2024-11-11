// list.h

#ifndef LIST_H
#define LIST_H

#include <iostream>

// Эта структура хранит один элемент списка
struct list_item {
    int data; // Данные, хранящиеся в элементе
    list_item* next; // Указатель на следующий элемент
    list_item* previous; // Указатель на предыдущий элемент

    // Конструктор для создания нового элемента
    list_item(int _data);
};

// Эта структура управляет списком в целом
struct list {
    list_item* first; // Указатель на первый элемент списка
    list_item* last; // Указатель на последний элемент списка
    list_item* current; // Указатель на текущий элемент списка

    // Конструктор для инициализации пустого списка
    list();

    // Деструктор для очистки списка и освобождения памяти
    ~list();

    // Проверяет, пуст ли список
    bool is_empty();

    // Добавляет новый элемент в конец списка
    void push_back(int data);

    // Добавляет новый элемент в начало списка
    void push_front(int data);

    // Вставляет новый элемент в текущую позицию
    void insert_at_current(int data);

    // Перемещает текущий указатель на следующий элемент
    void move_current_right();

    // Перемещает текущий указатель на предыдущий элемент
    void move_current_left();

    // Удаляет первый элемент списка
    void delete_first();

    // Удаляет последний элемент списка
    void delete_last();

    // Удаляет текущий элемент списка
    void delete_current();

    // Печатает список от начала до конца
    void print_list();

    // Печатает список от конца до начала
    void print_list_reverse();

    // Разбивает список на два по текущему элементу
    void split_at_current(list& new_list);
};

#endif // LIST_H

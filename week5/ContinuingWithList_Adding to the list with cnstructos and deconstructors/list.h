// list.h

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

// Структура для хранения одного элемента списка
struct list_item {
    int data; // Данные элемента
    list_item* next; // Указатель на следующий элемент
    list_item* previous; // Указатель на предыдущий элемент

    // Конструктор для создания элемента с заданными данными
    list_item(int _data);
};

// Класс для управления списком в целом
class list {

private:
    list_item* first; // Указатель на первый элемент списка
    list_item* last; // Указатель на последний элемент списка
    list_item* current; // Указатель на текущий элемент списка

public:

    // Конструктор по умолчанию
    list();

    // Конструктор копирования
    list(const list& other);

    // Конструктор перемещения
    list(list&& other);

    // Оператор присваивания копированием
    list& operator=(const list& other);

    // Оператор присваивания перемещением
    list& operator=(list&& other);

    // Деструктор
    ~list();

    // Геттер для данных текущего элемента
    int get_current_data() const;

    // Метод для установки текущего элемента на первый
    void set_current_to_first();

    // Метод для установки текущего элемента на последний
    void set_current_to_last();

    // Метод для установки текущего элемента по значению данных
    bool set_current_by_value(int value);

    // Геттер для данных первого элемента
    int get_first_data() const;

    // Сеттер для данных первого элемента
    void set_first_data(int value);

    // Проверяет, пуст ли список
    bool is_empty() const;

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
    void print_list() const;

    // Печатает список от конца до начала
    void print_list_reverse() const;

    // Разбивает список на два по текущему элементу
    void split_at_current(list& new_list);

    // Перегруженные операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const list& lst);
    friend std::istream& operator>>(std::istream& is, list& lst);

    // Оператор конкатенации списков
    list operator+(const list& other) const;
    list operator+(list&& other);

    // Дополнительный метод для очистки списка
    void clear();
};

#endif // LIST_H


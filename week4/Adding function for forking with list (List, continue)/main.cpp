// main.cpp

#include <iostream>
#include "list.h"

using namespace std;

int main() {
    // Создаем список
    list l;

    cout << "Добавляем элементы в конец списка: 28, 37, 21, 4" << endl;
    l.push_back(28);
    l.push_back(37);
    l.push_back(21);
    l.push_back(4);

    // Печатаем список
    l.print_list();

    // Устанавливаем текущий элемент на второй элемент списка
    l.current = l.first->next;
    cout << "Текущий элемент установлен на второй элемент: " << l.current->data << endl;

    // Вставляем элемент в текущую позицию
    cout << "Вставляем 99 в текущую позицию" << endl;
    l.insert_at_current(99);

    // Печатаем список
    l.print_list();

    // Перемещаем текущий элемент вправо и вставляем новый элемент
    cout << "Перемещаем текущий элемент вправо" << endl;
    l.move_current_right();
    cout << "Текущий элемент: " << l.current->data << endl;

    cout << "Вставляем 55 в текущую позицию" << endl;
    l.insert_at_current(55);

    // Печатаем список
    l.print_list();

    // Удаляем текущий элемент
    cout << "Удаляем текущий элемент" << endl;
    l.delete_current();

    // Печатаем список
    l.print_list();

    // Устанавливаем текущий элемент на первый и удаляем его
    l.current = l.first;
    cout << "Текущий элемент установлен на первый: " << l.current->data << endl;
    cout << "Удаляем текущий элемент" << endl;
    l.delete_current();

    // Печатаем список
    l.print_list();

    // Удаляем последний элемент
    cout << "Удаляем последний элемент" << endl;
    l.delete_last();

    // Печатаем список
    l.print_list();

    // Печатаем список в обратном порядке
    l.print_list_reverse();

    // Демонстрируем перемещение текущего элемента
    l.current = l.first;
    cout << "Текущий элемент: " << l.current->data << endl;
    l.move_current_right();
    cout << "Переместились вправо. Текущий элемент: " << l.current->data << endl;
    l.move_current_left();
    cout << "Переместились влево. Текущий элемент: " << l.current->data << endl;

    // Добавляем элемент в начало списка
    cout << "Добавляем 77 в начало списка" << endl;
    l.push_front(77);

    // Печатаем список
    l.print_list();

    // Разбиваем список на два по текущему элементу
    cout << "Разбиваем список на два по текущему элементу" << endl;
    list l2;
    l.split_at_current(l2);

    cout << "Первый список:" << endl;
    l.print_list();

    cout << "Второй список:" << endl;
    l2.print_list();

    // При выходе из main будут вызваны деструкторы списков, освобождая память

    return 0;
}

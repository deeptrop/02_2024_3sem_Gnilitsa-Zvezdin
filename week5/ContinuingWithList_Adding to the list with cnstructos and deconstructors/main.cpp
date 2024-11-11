// main.cpp

#include <iostream>
#include "list.h"

using namespace std;

int main() {
    
    list l1;
    cout << "Введите элементы для списка l1 (через пробел, завершите ввод не числом): ";
    cin >> l1; 

    cout << "Список l1: " << l1 << endl;

    // Устанавливаем текущий элемент на второй элемент списка
    l1.current = l1.first;
    l1.move_current_right(); // Перемещаем текущий указатель вправо

    // Разбиваем список l1 на два списка по текущему элементу
    list l2;
    l1.split_at_current(l2);

    cout << "После разделения:" << endl;
    cout << "Список l1: " << l1 << endl;
    cout << "Список l2: " << l2 << endl;

    // Копирование
    list l3 = l1 + l2;
    cout << "Список l3 = l1 + l2: " << l3 << endl;

    // перемещение временных объектов
    list l4 = l1 + std::move(l2);
    cout << "Список l4 = l1 + move(l2): " << l4 << endl;
    cout << "Список l2 после перемещения: " << l2 << endl;

    //  оператор присваивания копированием
    list l5;
    l5 = l3;
    cout << "Список l5 = l3: " << l5 << endl;

    //  присваивания перемещением
    list l6;
    l6 = std::move(l3);
    cout << "Список l6 = move(l3): " << l6 << endl;
    cout << "Список l3 после перемещения: " << l3 << endl;

    // l6 в обратном порядке
    cout << "Список l6 в обратном порядке: ";
    l6.print_list_reverse();

    // +элементв начало l6
    l6.push_front(100);
    l6.push_front(200);
    cout << "Список l6 после добавления элементов в начало: " << l6 << endl;

    // установление текущего эл. и его удаоение
    l6.current = l6.first;
    l6.move_current_right();
    cout << "Текущий элемент l6: " << l6.current->data << endl;
    cout << "Удаляем текущий элемент" << endl;
    l6.delete_current();
    cout << "Список l6 после удаления текущего элемента: " << l6 << endl;

    return 0;
}

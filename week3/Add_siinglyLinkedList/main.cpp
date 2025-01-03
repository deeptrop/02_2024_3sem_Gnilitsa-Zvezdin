#include <iostream>
using namespace std;



// Структура для хранения одного элемента списка
struct list_item {
    int data; // Поле для хранения данных
    list_item* next; // Указатель на следующий элемент
    list_item* previous; // Указатель на предыдущий элемент

    // Конструктор для инициализации элемента списка
    list_item(int _data) : data(_data), next(nullptr), previous(nullptr) {}
};

// Структура для управления списком вцелом
struct list {
    list_item* first; 
    list_item* last; 
    list_item* current; 

    // Конструктор для инициализации пустого списка
    list() : first(nullptr), last(nullptr), current(nullptr) {}
};

// Функция проверки пуст ли список
bool is_list_empty(list* my_list) {
    // Если указатель на первый элемент равен nullptr, список пуст
    if (my_list->first == nullptr) {
        return true;
    }
    return false;
}

// Функция добавления нового элемента в конец списка
void pushback(list* cur_list, int data) {
    // Создаие нового элемента
    list_item* p_tmp = new list_item(data);

    // Если список пуст новый элемент становится первым, последним и текущим.
    if (is_list_empty(cur_list)) {
        cur_list->first = p_tmp;
        cur_list->last = p_tmp;
        cur_list->current = p_tmp;
        return;
    }

    // Связываем новый элемент с последним элементом списка
    p_tmp->previous = cur_list->last; // предыдущий элемент для нового
    cur_list->last->next = p_tmp; // следующий элемент для текущего последнего
    cur_list->last = p_tmp; // Обновление указателя на последний элемент
}

// Функция добавления нового элемента в начало списка
void pushfront(list* cur_list, int data) {
    
    list_item* p_tmp = new list_item(data);

    // Если список пуст, новый элемент становится первым, последним и текущим
    if (is_list_empty(cur_list)) {
        cur_list->first = p_tmp;
        cur_list->last = p_tmp;
        cur_list->current = p_tmp;
        return;
    }

    // Связываем новый элемент с первым элементом 
    p_tmp->next = cur_list->first; 
    cur_list->first->previous = p_tmp; 
    cur_list->first = p_tmp; 
}

// Функция вставки нового элемента в текущий
void insert_at_current(list* cur_list, int data) {
   
    if (cur_list->current == nullptr) {
        pushback(cur_list, data);
        return;
    }

    
    list_item* p_tmp = new list_item(data);

    // Вставляем новый элемент перед текущим
    p_tmp->next = cur_list->current;
    p_tmp->previous = cur_list->current->previous;

    if (cur_list->current->previous != nullptr) {
        cur_list->current->previous->next = p_tmp;
    } else {
        // Если текущий элемент был первым обновляем указатель на первый элемент
        cur_list->first = p_tmp;
    }
    cur_list->current->previous = p_tmp;

    // Делаем новый элемент текущим.
    cur_list->current = p_tmp;
}

// Функция перемещения текущего указателя на следующий элемент
void move_current_right(list* cur_list) {
    if (cur_list->current != nullptr && cur_list->current->next != nullptr) {
        cur_list->current = cur_list->current->next;
    } else {
        cout << "Невозможно переместиться вправо, текущий элемент последний." << endl;
    }
}

// Функция перемещения текущего указателя на предыдущий элемент
void move_current_left(list* cur_list) {
    if (cur_list->current != nullptr && cur_list->current->previous != nullptr) {
        cur_list->current = cur_list->current->previous;
    } else {
        cout << "Невозможно переместиться влево, текущий элемент первый." << endl;
    }
}

// Функция удаления первого элемента списка.
void delete_first(list* cur_list) {
    if (is_list_empty(cur_list)) {
        cout << "Список пуст, нечего удалять." << endl;
        return;
    }

    list_item* to_delete = cur_list->first;

    // Если в списке только один элемент.
    if (cur_list->first == cur_list->last) {
        cur_list->first = nullptr;
        cur_list->last = nullptr;
        cur_list->current = nullptr;
    } else {
        cur_list->first = cur_list->first->next;
        cur_list->first->previous = nullptr;

        if (cur_list->current == to_delete) {
            cur_list->current = cur_list->first;
        }
    }

    delete to_delete; // Освобождаем память.
}

// Функция удаления последнего элемента списка.
void delete_last(list* cur_list) {
    if (is_list_empty(cur_list)) {
        cout << "Список пуст, нечего удалять." << endl;
        return;
    }

    list_item* to_delete = cur_list->last;

    // Если в списке только один элемент.
    if (cur_list->first == cur_list->last) {
        cur_list->first = nullptr;
        cur_list->last = nullptr;
        cur_list->current = nullptr;
    } else {
        cur_list->last = cur_list->last->previous;
        cur_list->last->next = nullptr;

        if (cur_list->current == to_delete) {
            cur_list->current = cur_list->last;
        }
    }

    delete to_delete; // Освобождаем память.
}

// Функция удаления текущего элемента списка.
void delete_current(list* cur_list) {
    if (cur_list->current == nullptr) {
        cout << "Текущий элемент не установлен, нечего удалять." << endl;
        return;
    }

    list_item* to_delete = cur_list->current;

    // Если элемент единственный в списке.
    if (cur_list->first == cur_list->last) {
        cur_list->first = nullptr;
        cur_list->last = nullptr;
        cur_list->current = nullptr;
    } else if (to_delete == cur_list->first) {
        // Если удаляем первый элемент.
        cur_list->first = to_delete->next;
        cur_list->first->previous = nullptr;
        cur_list->current = cur_list->first;
    } else if (to_delete == cur_list->last) {
        // Если удаляем последний элемент.
        cur_list->last = to_delete->previous;
        cur_list->last->next = nullptr;
        cur_list->current = cur_list->last;
    } else {
        // Удаляем элемент из середины списка.
        to_delete->previous->next = to_delete->next;
        to_delete->next->previous = to_delete->previous;
        cur_list->current = to_delete->next; // Перемещаем текущий на следующий элемент.
    }

    delete to_delete; // Освобождаем память.
}

// Функция печати списка от начала до конца.
void print_list(list* cur_list) {
    list_item* p_tmp = cur_list->first;
    cout << "Список от начала до конца:" << endl;
    while (p_tmp != nullptr) {
        cout << p_tmp->data << " ";
        p_tmp = p_tmp->next;
    }
    cout << endl;
}

// Функция печати списка от конца до начала.
void print_list_reverse(list* cur_list) {
    list_item* p_tmp = cur_list->last;
    cout << "Список от конца до начала:" << endl;
    while (p_tmp != nullptr) {
        cout << p_tmp->data << " ";
        p_tmp = p_tmp->previous;
    }
    cout << endl;
}

int main() {
    list l;

    pushback(&l, 28);
    pushback(&l, 37);
    pushback(&l, 21);
    pushback(&l, 4);

 
    print_list(&l);

    l.current = l.first->next;

    insert_at_current(&l, 99);

    print_list(&l);

    move_current_right(&l);
    insert_at_current(&l, 55);

    
    print_list(&l);

    
    delete_current(&l);

    
    print_list(&l);

    
    l.current = l.first;
    delete_current(&l);

    
    print_list(&l);

    
    delete_last(&l);

    
    print_list(&l);

    //  список в обратном порядке
    print_list_reverse(&l);

    
    l.current = l.first;
    cout << "Текущий элемент: " << l.current->data << endl;
    move_current_right(&l);
    cout << "Переместились вправо. Текущий элемент: " << l.current->data << endl;
    move_current_left(&l);
    cout << "Переместились влево. Текущий элемент: " << l.current->data << endl;

    
    pushfront(&l, 77);

    
    print_list(&l);

    
    while (!is_list_empty(&l)) {
        delete_first(&l);
    }

   
    print_list(&l);

    return 0;
}

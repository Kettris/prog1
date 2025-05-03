#include "doubly_linked_list.hpp"

using biv::DoublyLinkedList;

//деструктор
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* current = begin;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;        
    }
    begin = nullptr;
    end = nullptr;
}

//получение размера списка
template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
    return size;
}

//проверка наличия элемента
template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
    Node* current = begin;
    while (current) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

//печать элементов списка
template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
    Node* current = begin;
    if (!current) {
        std::cout << "empty" << std::endl; //если пустой
        return;
    }
    while (current) {
        std::cout << current->value << ' '; 
        current = current->next;
    } 
    std::cout << std::endl;
}

//добавление элемента в конец списка
template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* new_node = new Node(value);
    if (!begin) {
        begin = new_node;
        end = new_node;
    } 
    else {
        end->next = new_node;
        new_node->prev = end;
        end = new_node;
    }    
    ++size;
}

//удаление последнего элемента
template<typename T>
bool DoublyLinkedList<T>::remove_last() noexcept {
    if (!end) {
        return false; //если список пуст
    }
    
    Node* node_to_remove = end;
    end = end->prev; //сдвиг конца
    
    if (end) {
        end->next = nullptr; //обновление указателя на след
    } 
    else {
        begin = nullptr; //если список становится пустым
    }
    delete node_to_remove; //удаление узла
    --size;
    return true; 
}

//удаление первого найденного элемента
template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
    Node* current = begin;
    while (current) {
        if (current->value == value) {
            if (current == begin) {
                begin = current->next; 
                if (begin) {
                    begin->prev = nullptr; //обновление предыдущ  узла
                } 
                else {
                    end = nullptr; //если список стал пустым
                }
            } 
            else if (current == end) {
                end = current->prev;
                end->next = nullptr;
            } 
            else {
                Node* next_node = current->next;
                Node* prev_node = current->prev;
                prev_node->next = next_node; 
                if (next_node) {
                    next_node->prev = prev_node;
                }
            }
            delete current;
            --size;
            return true;
        }
        current = current->next;
    } 
    return false;
}
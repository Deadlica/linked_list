#ifndef T_LINKED_LIST_H
#define T_LINKED_LIST_H

#include <iostream>

template<typename T>
class linked_list {
public:
    linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    linked_list(const linked_list& src) {
        head = nullptr;
        tail = nullptr;
        *this = src;
    }

    ~linked_list() {
        while(!is_empty()) {
            pop_front();
        }
    }

    linked_list<T>& operator=(const linked_list<T>& rhs) {
        if(this != &rhs) {
            while(!is_empty()) {
                this->pop_front();
            }
            node* it = rhs.head;
            while(it != nullptr) {
                this->push_back(it->value);
                it = it->next;
            }
        }
        return *this;
    }

    //appends elements from rhs
    linked_list<T>& operator+=(const linked_list<T>& rhs) {
        node* it = rhs.head;
        if(this != &rhs) {
            while(it != nullptr) {
                this->push_back(it->value);
                it = it->next;
            }
        }
        else {
            linked_list<T> temp_list;
            while(it != nullptr) {
                temp_list.push_back(it->value);
                it = it->next;
            }
            it = temp_list.head;
            while(it != nullptr) {
                this->push_back(it->value);
            }
        }
        return *this;
    }

    //inserting elements
    void insert(T value, size_t pos) {
        if(pos == 0) {
            push_front();
        }
        else if(pos > 0 && pos < size()) {
        node* newElement = new node(value);
        node* it = head;
        for(size_t index = 0; index < pos; index++, it = it->next) {}
        newElement->next = it;
        newElement->prev = it->prev;
        it->prev->next = newElement;
        it->prev = newElement;
        }
        else {
            std::cerr << "Invalid position!" << std::endl;
        }
    }

    void push_front(T value) {
        node* newElement = new node(value);
        if(is_empty()) {
            head = newElement;
            tail = newElement;
        }
        else {
            newElement->next = head;
            head->prev = newElement;
            head = newElement;
        }
    }

    void push_back(T value) {
        node* newElement = new node(value);
        if(is_empty()) {
            head = newElement;
            tail = newElement;
        }
        else {
            newElement->prev = tail;
            tail->next = newElement;
            tail = newElement;
        }
    }

    //accessing elements
    T front() const {
        if(!is_empty()) {
            return head->value;
        }
        else {
            exit(-1);
        }
    }
    T back() const {
        if(!is_empty()) {
            return tail->value;
        }
        else {
            exit(-1);
        }
    }
    T at(size_t pos) const {
        if(pos < 0 || pos >= size()) {
            std::cerr << "Invalid index!" << std::endl;
            exit(-1);
        }
        else if(pos == 0) {
            return head->value;;
        }
        else if(pos == size() - 1) {
            return tail->value;
        }
        else {
            node* it = head;
            for(size_t index = 0; index < pos; index++, it = it->next) {}
            return it->value;
        }
    }

    //removing elements
    void remove(size_t pos) {
        if(pos < 0 || pos >= size()) {
            std::cout << "This element doesn't exist!" << std::endl;
        }
        else if(pos == 0) {
            pop_front();
        }
        else if(pos == size() - 1) {
            pop_back();
        }
        else {
            node* it = head;
            for(size_t index = 0; index < pos; index++, it = it->next) {}
            it->prev->next = it->next;
            it->next->prev = it->prev;
            delete it;
        }
    }

    T pop_front() {
        T value = head->value;
        if(is_empty()) { //Empty
            std::cerr << "List is empty!" << std::endl;
            exit(-1);
        }
        else if(size() == 1) { //One element
            delete head;
            head = nullptr, tail = nullptr;
        }
        else { //Multiple elements
            node * remove = head;
            head = head->next;
            head->prev = nullptr;
            delete remove;
        }
        return value;
    }

    T pop_back() {
        T value = tail->value;
        if(is_empty()) { //Empty
            std::cerr << "List is empty!" << std::endl;
            exit(-1);
        }
        else if(size() == 1) { //One element
            delete head;
            head = nullptr, tail = nullptr;
        }
        else { //Multiple elements
            node* remove = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete remove;
        }
        return value;
    }

    //status
    size_t size() const {
        size_t size = 0;
        for(node* it = head; it != nullptr; it = it->next, size++) {}
        return size;
    }
    bool is_empty() const {
        return head == nullptr && tail == nullptr;
    }

    //output
    void print() const {
        for(node* it = head; it != nullptr; it = it->next) {
            std::cout << it->value << ", ";
        }
        std::cout << std::endl;
    }
    void print_reverse() const {
        for(node* it = tail; it != nullptr; it = it->prev) {
            std::cout << it->value << ", ";
        }
        std::cout << std::endl;
    }

private:
    struct node {
        node(T value) { //Constructor for the node
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
        T value;
        node* next;
        node* prev;
    };
    node* head;
    node* tail;
};

#endif
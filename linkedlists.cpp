#include "linkedlists.h"

linked_list::linked_list() {
    head = nullptr;
    tail = nullptr;
}
linked_list::linked_list(const linked_list& src) {}

linked_list::~linked_list() {}

//Assign list to new with = operator
linked_list & linked_list::operator =(const linked_list& rhs) {return *this;}

// appends elements from rhs
linked_list & linked_list::operator +=(const linked_list& rhs) {return *this;}

// inserting elements
void linked_list::insert(double value, size_t pos) {
    if(pos == 0) {
        push_front(value);
    }
    else if(pos > size()) {
        std::cout << "The given position is bigger than the list size" << std::endl;
    }
    else {
        node* it = head;
        node* itNext;
        //Indexing up until it's at the element before insert pos
        for(size_t i = 0; i < (pos - 1); i++) {
            it = it->next;
        }
        //Extra node so that node n->next can connect to rest of list
        itNext = it->next;
        node* n = new node(value);
        //Connecting node n in the list
        it->next = n;
        n->prev = it;
        n->next=itNext;
        if(pos == size() - 1) tail = n;
    }
}
void linked_list::push_front(double value) {
    node* n = new node(value);
    if(head == nullptr) {
        head = n;
        tail = n;
    }
    else {
        head->prev = n;
        n->next = head;
        head = n;
    }

}
void linked_list::push_back(double value) {
    node* n = new node(value);
    if(head == nullptr) {
        head = n;
        tail = n;
    }
    else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

// accessing elements
double linked_list::front() const {
    double frontElement = head->value;
    return frontElement;
    }
double linked_list::back() const {
    double backElement;
    backElement = tail->value;
    return backElement;
    }
double linked_list::at(size_t pos) const {
    double atElement;
    node* it = head;
    for(size_t i = 0; i < pos; i++){
        it = it->next;
    }
    atElement = it->value;
    return atElement;
    }

// removing elements
void linked_list::remove(size_t pos) {

}
double linked_list::pop_front() {
    double removedFrontElement;
    node* frontPop = head;
    removedFrontElement = frontPop->value;
    head = head->next;
    head->prev = nullptr;
    frontPop->next = nullptr;
    return removedFrontElement;
    }
double linked_list::pop_back() {
    double removedBackElement;
    node* backPop = tail;
    removedBackElement = backPop->value;
    tail = tail->prev;
    tail->next = nullptr;
    backPop->prev = nullptr;
    return removedBackElement;
    }

// status
size_t linked_list::size() const {
    node* it = head;
    size_t sizeCounter = 0;
    while(it != nullptr) {
        sizeCounter++;
        it = it->next;
    }
    return sizeCounter;
    }
bool linked_list::is_empty() const {
    if(head == nullptr && tail == nullptr) return true;
    else return false;
    }

// output
void linked_list::print() const {
    node* it = head;
    while(it != nullptr) {
        std::cout << it->value;
        it = it->next;
        if(it != nullptr) std::cout << ", ";
    }
    std::cout << std::endl;
}
void linked_list::print_reverse() const {
    node* it = tail;
    while(it != nullptr) {
        std::cout << it->value;
        it = it->prev;
        if(it != nullptr) std::cout << ", ";
    }
    std::cout << std::endl;
}

linked_list::node::node(double value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
}
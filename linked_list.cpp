/*
Samuel Greenberg
08/04/2021
Lab 2 Linked lists
DT109G
*/

#include "linked_list.h"

linked_list::linked_list() {
    //Empty list, head and tail doesn't have anything to point to
    head = nullptr;
    tail = nullptr;
}
linked_list::linked_list(const linked_list& src) {
    //Copy constructor works the same as the '=' operator
    head = nullptr;
    tail = nullptr;
    *this = src;
}

linked_list::~linked_list() {
    if(!is_empty()) { //List isn't empty
        node* it = head;
        while(it != nullptr) { //Iterate through each element, delete them one by one
            it = it->next;
            pop_front();
        }
    }
}

linked_list& linked_list::operator=(const linked_list& rhs) {
    if(this != &rhs) { //If 'this' and 'rhs' are the same nothing needs to be done
        node* it = rhs.head;
        while(!is_empty()) {
            pop_front();
        }
        while(it != nullptr) { //Filling list with rhs element by using push_back
            push_back(it->value);
            it = it->next;
        }
    }
    return *this;
}

//appends elements from rhs
linked_list& linked_list::operator+=(const linked_list& rhs) {
    node* it = rhs.head;
    if(this != &rhs) { //If the given lists aren't the same one
        while(it != nullptr) {
            push_back(it->value);
            it = it->next;
        }
    }
    else {
        //If it's appending itself it would infinitely loop
        //Therefore creating a temp list and assign rhs to it
        //Then appending temp to 'this'
        linked_list temp;
        while(it != nullptr) {
            temp.push_back(it->value);
            it = it->next;
        }
        it = temp.head;
        while(it != nullptr) {
            push_back(it->value);
            it = it->next;
        }
    }
    return *this;
    }

//inserting elements
void linked_list::insert(double value, size_t pos) {
    if(pos == 0) { //Front position
        push_front(value);
    }
    else if(pos == size() - 1) { //Back position
        push_back(value);
    }
    else {
        //Indexing up to given position which the new node will occupy
        //Connect it->next to the new node 'n' and 'n'->next = it
        node* it = head;
        node* n = new node(value);
        for(size_t i = 0; i < pos; i++) {
            it = it->next;
        }
        (it->prev)->next = n;
        n->prev = it->prev;
        it->prev = n;
        n->next = it;
    }
}
void linked_list::push_front(double value) {
    node* n = new node(value);
    if(!is_empty()) {
        //Connecting new node to head, when it's double linked, head is set to the new node
        n->next = head;
        head->prev = n;
        head = n;
        head->prev = nullptr;
    }
    else { //It's the first element to be added, head and tail points to the same node
        head = n;
        tail = n;
    }
}
void linked_list::push_back(double value) {
    node* n = new node(value);
    if(!is_empty()) {
        //Connecting new node to tail, when it's double linked, tail is set to the new node
        n->prev = tail;
        tail->next = n;
        tail = n;
        tail->next = nullptr;
    }
    else { //It's the first element to be added, head and tail points to the same node
        head = n;
        tail = n;
    }
}

//accessing elements
double linked_list::front() const {
    if(!is_empty()) { //List isn't empty
        double num = head->value;
        return num;
    }
    else {
        exit(1);
    }
}
double linked_list::back() const {
    if(!is_empty()) { //List isn't empty
        double num = tail->value;
        return num;
    }
    else {
        exit(1);
    }
}
double linked_list::at(size_t pos) const {
    if(!is_empty()) {
        if(size() == 0) { //If the list is empty
            std::cout << "The list is empty." << std::endl;
            exit(1);
        }
        else if(pos >= size()) { //Given index doesn't exist in list
            std::cout << "That indexed element doesn't exist" << std::endl;
            exit(1);
        }       

        else { //Indexing up to given position, assigning it to 'num'
            node* it = head;
            for(size_t i = 0; i < pos; i++) {
                it = it->next;
            }
            double num = it->value;
            return num;
        }
    }
    else {
        exit(1);
    }
}

//removing elements
void linked_list::remove(size_t pos) {
    if(!is_empty()) {
        if(pos == 0) { //If it's the front element
            pop_front();
        }
        else if(pos == size() - 1) { //If it's the back element
            pop_back();
        }
        else if(pos >= size()) { //If the given position is higher than the back element index
            std::cout << "This element doesn't exist" << std::endl;
        }
        else { //Iterate to the node that's getting removed
            node* remove = head;
            for(size_t i = 0; i < pos; i++) {
                remove = remove->next;
            }
            //Disconnecting prev, next node from 'remove', then deleting node 'remove'
            (remove->prev)->next = remove->next;
            (remove->next)->prev = remove->prev;
            remove->next = nullptr;
            remove->prev = nullptr;
            delete remove;
        }
    }
}
double linked_list::pop_front() {
    double removedNum;
    node* n = head;
    if(size() == 1) { //If it's the last element, setting head, tail to null and then removing node
        removedNum = head->value;
        head = nullptr;
        tail = nullptr;
        n->prev = nullptr;
        n->next = nullptr;
        delete n;
        return removedNum;
    }
    else if(!is_empty()) { //Create a new pointer to remove the back element and traversing head forwards once
        removedNum = head->value;
        head = head->next;
        head->prev = nullptr;
        n->next = nullptr;
        delete n;
        return removedNum;
    }
    else {
        std::cout << "There's no elements in the list" << std::endl;
        exit(1);
    }
}
double linked_list::pop_back() {
    double removedNum;
    node* n = tail;
    if(size() == 1) { //If it's the last element, setting head, tail to null and then removing node
        removedNum = tail->value;
        head = nullptr;
        tail = nullptr;
        n->prev = nullptr;
        n->next = nullptr;
        delete n;
        return removedNum;
    }
    else if(!is_empty()) { //Create a new pointer to remove the back element and traversing tail backwards once
        removedNum = tail->value;
        tail = tail->prev;
        tail->next = nullptr;
        n->prev = nullptr;
        delete n;
        return removedNum;
    }
    else {
        std::cout << "There's no elements in the list" << std::endl;
        exit(1);
    }
}

//status
size_t linked_list::size() const {
    size_t counter = 0;
    //Each time 'it' isn't null count up by 1
    if(!is_empty()) {
        node* it = head;
        while(it != nullptr) {
            counter++;
            it = it->next;
        }
    }
    return counter;
}
bool linked_list::is_empty() const {
    if(head == nullptr && tail == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

//output
void linked_list::print() const {
    //As long as list isn't empty
    //Iterate through each node and print it
    if(!is_empty()) {
        node* it = head;
        while(it != nullptr) {
            std::cout << it->value;
            it = it->next;
            if(it != nullptr) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}
void linked_list::print_reverse() const {
    //As long as list isn't empty
    //Iterate backwards through each node and print it
    if(!is_empty()) {
        node* it = tail;
        while(it != nullptr) {
            std::cout << it->value;
            it = it->prev;
            if(it != nullptr) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}

linked_list::node::node(double value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
}
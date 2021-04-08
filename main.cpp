#include "linkedlists.h"

int main() {
    std::cout << "Hej" << std::endl;
    linked_list clone;
    int test = 9;
    clone.push_back(test);
    clone.push_back(17);
    clone.push_back(3);
    clone.push_back(5);
    clone.push_front(99);
    clone.push_front(88);
    clone.push_front(77);
    clone.push_front(66);
    clone.push_back(66);
    clone.print();
    clone.insert(1337, 9);
    clone.print();


    return 0;
}
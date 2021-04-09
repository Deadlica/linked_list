#include "linkedlists.h"

int main() {
    std::cout << "Hej" << std::endl;
    linked_list clone;
    linked_list list;
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
    list = clone;
    list.print();
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.print();
    list = clone;
    clone.print();
    std::cout << std::endl << std::endl;
    linked_list wtf;
    wtf.push_back(1);
    wtf.push_back(2);
    wtf.push_back(3);
    wtf.push_back(4);
    wtf.push_back(5);
    wtf.print();
    wtf = clone;
    wtf.print();
    clone.print();
    wtf.push_back(11);
    wtf.print();
    wtf.pop_front();
    wtf.print();
    linked_list yoo;
    clone.print();
    yoo += clone;
    yoo.print();
    std::cout << "i know it's messy with all the prints but dill wit it ;)" << std::endl;
    yoo += clone;
    yoo.print();
    yoo.pop_back();
    yoo.pop_back();
    yoo.pop_front();
    yoo.insert(69, 8);
    std::cout << "-------------------------------" << std::endl;
    yoo.print();
    clone.print();
    wtf.print();
    list.print();


    return 0;
}
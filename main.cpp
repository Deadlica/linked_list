/*
Samuel Greenberg
09/04/2021
Labb 2 Linked Lists
DT019G
*/

#include "linkedlists.h"
#include <ctime>
#include <cstdlib>

void print_list(linked_list l);
linked_list merge(linked_list& list1, linked_list& list2);
bool isSorted(linked_list l);

int main() {
    linked_list list1, list2;
    srand((unsigned) time(0));
    int randNum1, randNum2;
    std::cout << "Filling list1, list2 with 50 random numbers each..." << std::endl;
    for(size_t i = 0; i < 49; i++) {
        if(i == 0) {
            list1.push_back(0);
            list2.push_back(0);
        }
        randNum1 = list1.back() + (rand() % 5);
        randNum2 = list2.back() + (rand() % 5);
        list1.push_back(randNum1);
        list2.push_back(randNum2);
    }

    std::cout << "DONE!" << std::endl << std::endl << "list1: ";
    list1.print();
    std::cout << std::endl << "list2: ";
    list2.print();

    pressEnterToContinue();
    std::cout << "Checking which lists 25th element is bigger..." << std::endl;

    if(list1.at(25) > list2.at(25)) {
        std::cout << "List1's 25th element: " << list1.at(25) << std::endl
        << "List2's 25th element: " << list2.at(25) << std::endl
        << "Removing " << list1.at(25) << " from list1." << std::endl;
        list1.remove(25);
    }
    else if(list1.at(25) < list2.at(25)) {
        std::cout << "List1's 25th element: " << list1.at(25) << std::endl
        << "List2's 25th element: " << list2.at(25) << std::endl
        << "Removing " << list2.at(25) << " from list2." << std::endl;
        list2.remove(25);
    }
    else if(list1.at(25) == list2.at(25)) {
        std::cout << "List1's 25th element: " << list1.at(25) << std::endl
        << "List2's 25th element: " << list2.at(25) << std::endl
        << "Both lists 25th element are the same size." << std::endl << std::endl
        << "ABORTING PROGRAM!" << std::endl;
        return 0;
    }
    pressEnterToContinue();

    linked_list list3;
    if(list1.size() < list2.size()) {
        std::cout << "Creating 'list3' and assigning list1 to it, then printing list3 in reverse order." << std::endl;
        list3 = list1;
    }
    else if (list1.size() > list2.size()) {
        std::cout << "Creating 'list3' and assigning list2 to it, then printing list3 in reverse order." << std::endl;
        list3 = list2;
    }
    else {
        std::cout << "Both lists are the same size." << std::endl;
    }

    std::cout << "list3:" << std::endl;
    list3.print_reverse();
    pressEnterToContinue();


    if(list1.size() == 50) {
        std::cout << "Removing every other element from list1." << std::endl << "list1: ";
        for(size_t i = 0; i < 25; i++) {
            list1.pop_back();
            list1.push_front(list1.pop_back());
        }
        print_list(list1);
    }

    else if(list2.size() == 50) {
        std::cout << "Removing every other element from list2." << std::endl << "list2: ";
        for(size_t i = 0; i < 25; i++) {
            list2.pop_back();
            list2.push_front(list2.pop_back());
        }
        print_list(list2);
    }

    pressEnterToContinue();

    std::cout << "Merging list1, list2 into a new list called list4." << std::endl;
    linked_list list4 = merge(list1, list2);
    std::cout << "list4: ";
    print_list(list4);

    pressEnterToContinue();

    std::cout << "Double checking that the merged list4 is sorted.." << std::endl;
    if(isSorted(list4)) std::cout << "True" << std::endl;
    else std::cout << "False" << std::endl;

    return 0;
}

void print_list(linked_list l) {
    l.print();
}

linked_list merge(linked_list& list1, linked_list& list2) {
    linked_list list4;
    while(!list1.is_empty() && !list2.is_empty()) {
        if(list1.front() < list2.front()) {
            list4.push_back(list1.front());
            list1.pop_front();
        }
        else if(list2.front() < list1.front()) {
            list4.push_back(list2.front());
            list2.pop_front();
        }
        else {
            list4.push_back(list1.front());
            list4.push_back(list2.front());
            list1.pop_front();
            list2.pop_front();
        }
    }
    if(!list1.is_empty()) {
        list4 += list1;
    }
    else if(!list2.is_empty()) {
        list4 += list2;
    }
    return list4;
}

bool isSorted(linked_list l) {
    for(size_t i = 0; i < l.size(); i++) {
        if(i == l.size() - 1) break;
        if(l.at(i) > l.at(i + 1)) return false;
    }
    
    return true;
}
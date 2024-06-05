#include<iostream>
#include "EList.h"


int main() {
    // EList()
    EList<int> el_0;

    // EList(size_type, const value_type&), push_back(const value_type&)
    EList<int> el_1(1, 5);
    el_1.push_back(7);


    return 0;
}

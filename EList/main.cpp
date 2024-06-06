#include "EList.h"


int main() {
    // EList(size_type, const value_type&), push_back(const value_type&), push_front(const value_type&), size()
    EList<int> el_1(1, 3);
    el_1.push_back(5);
    el_1.push_front(2);
    EList<int>::size_type count_1 = el_1.size();

    // EList(), pop_back(), pop_front()
    EList<int> el_2;
    el_2.push_back(2);
    el_2.push_back(3);
    el_2.push_back(5);
    el_2.pop_back();
    el_2.pop_front();


    return 0;
}

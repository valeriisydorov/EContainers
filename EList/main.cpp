#include "EList.h"
#include <list>


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

    // Iterator(), begin(), end()
    EList<int> el_3;
    EList<int>::iterator it_3_1 = el_3.begin();
    EList<int>::iterator it_3_2 = el_3.end();

    // Iterator(pointer_type, container_pointer)
    const EList<int> el_4(1, 7);
    EList<int>::const_iterator it_4_1 = el_4.begin();
    EList<int>::const_iterator it_4_2 = el_4.end();

    // operator*()
    EList<int> el_5_1;
    el_5_1.push_back(11);
    EList<int>::iterator it_5_1 = el_5_1.begin();
    *it_5_1 = 13;
    int i_5_1 = *it_5_1;
    const EList<int> el_5_2(1, 17);
    EList<int>::const_iterator it_5_2 = el_5_2.begin();
    // *it_5_2 = 19;
    int i_5_2 = *it_5_2;

    // operator->();
    EList<int> el_6;
    el_6.push_back(19);
    EList<int>::iterator it_6 = el_6.begin();
    it_6->set_data(23);
    int i_6 = it_6->get_data();

    // operator++()
    EList<int> el_7;
    el_7.push_back(2);
    el_7.push_back(3);
    el_7.push_back(5);
    EList<int>::iterator it_7 = el_7.begin();
    ++it_7;
    int i_7 = *it_7;

    // operator--()
    EList<int> el_8;
    el_8.push_back(7);
    el_8.push_back(11);
    el_8.push_back(13);
    EList<int>::iterator it_8 = el_8.end();
    --it_8;
    int i_8 = *it_8;

    // Iterator operator++(int)
    EList<int> el_9;
    el_9.push_back(11);
    el_9.push_back(13);
    el_9.push_back(17);
    EList<int>::iterator it_9 = el_9.begin();
    int i_9_1 = *it_9++;
    int i_9_2 = *it_9;

    // Iterator operator--(int)
    EList<int> el_10;
    el_10.push_back(13);
    el_10.push_back(17);
    el_10.push_back(19);
    EList<int>::iterator it_10 = el_10.end();
    it_10--;
    int i_10 = *it_10;


    return 0;
}

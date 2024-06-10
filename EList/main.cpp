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

    // Iterator(), begin(), end()
    EList<int> el_3;
    EList<int>::iterator it_3_1 = el_3.begin();
    EList<int>::iterator it_3_2 = el_3.end();

    // Iterator(pointer_type)
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
    // not work *it_5_2 = 19;
    int i_5_2 = *it_5_2;

    // operator->();
    EList<int> el_6;
    el_6.push_back(19);
    EList<int>::iterator it_6 = el_6.begin();
    it_6->set_data(23);
    int i_6 = it_6->get_data();




    return 0;
}

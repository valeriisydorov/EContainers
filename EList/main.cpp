#include <utility>
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

    // operator++(int)
    EList<int> el_9;
    el_9.push_back(11);
    el_9.push_back(13);
    el_9.push_back(17);
    EList<int>::iterator it_9 = el_9.begin();
    int i_9_1 = *it_9++;
    int i_9_2 = *it_9;

    // operator--(int)
    EList<int> el_10;
    el_10.push_back(13);
    el_10.push_back(17);
    el_10.push_back(19);
    EList<int>::iterator it_10 = el_10.end();
    it_10--;
    int i_10 = *it_10;

    // operator+(difference_type)
    EList<int> el_11;
    el_11.push_back(2);
    el_11.push_back(3);
    el_11.push_back(5);
    el_11.push_back(7);
    EList<int>::iterator it_11 = el_11.begin() + 3;
    int i_11_1 = *it_11;
    int i_11_2 = *(it_11 + (-1));

    // operator-(difference_type)
    EList<int> el_12;
    el_12.push_back(11);
    el_12.push_back(13);
    el_12.push_back(17);
    el_12.push_back(19);
    EList<int>::iterator it_12 = el_12.end() - 4;
    int i_12_1 = *it_12;
    int i_12_2 = *(it_12 - (-3));

    // operator==(const Iterator&, const Iterator&)
    EList<int> el_13;
    el_13.push_back(2);
    el_13.push_back(3);
    el_13.push_back(5);
    EList<int>::iterator it_13_1 = el_13.begin();
    EList<int>::iterator it_13_2 = el_13.end() - 3;
    bool r_13 = it_13_1 == it_13_2;

    // operator!=(const Iterator&, const Iterator&)
    EList<int> el_14_1;
    el_14_1.push_back(7);
    EList<int> el_14_2;
    el_14_2.push_back(7);
    EList<int>::iterator it_14_1 = el_14_1.begin();
    EList<int>::iterator it_14_2 = el_14_2.begin();
    bool r_14 = it_14_1 != it_14_2;

    // insert(size_type, const value_type&)
    EList<int> el_15;
    el_15.push_back(3);
    el_15.push_back(7);
    el_15.insert(0, 2);
    el_15.insert(3, 11);
    el_15.insert(2, 5);
    
    // operator[](size_type)
    EList<int> el_16_1;
    el_16_1.push_back(13);
    el_16_1.push_back(17);
    EList<int>::iterator it_16_1 = el_16_1[1];
    int i_16_1 = *it_16_1;
    const EList<int>& el_16_2 = el_16_1;
    EList<int>::const_iterator it_16_2 = el_16_2[1];
    int i_16_2 = *it_16_2;

    // EList(const EList&)
    EList<int> el_17_1;
    el_17_1.push_back(31);
    el_17_1.push_back(37);
    el_17_1.push_back(41);
    el_17_1.push_back(43);
    el_17_1.push_back(47);
    EList<int> el_17_2(el_17_1);

    // operator=(const EList&)
    EList<int> el_18_1;
    el_18_1.push_back(31);
    el_18_1.push_back(37);
    el_18_1.push_back(41);
    el_18_1.push_back(43);
    el_18_1.push_back(47);
    EList<int> el_18_2;
    el_18_2.push_back(11);
    el_18_2.push_back(13);
    el_18_2.push_back(17);
    el_18_2.push_back(19);
    el_18_2 = el_18_1;

    // EList(EList&&)
    EList<int> el_19_1;
    el_19_1.push_back(2);
    el_19_1.push_back(3);
    el_19_1.push_back(5);
    el_19_1.push_back(7);
    EList<int> el_19_2(std::move(el_19_1));

    // operator=(EList&&)
    EList<int> el_20_1;
    el_20_1.push_back(11);
    el_20_1.push_back(13);
    el_20_1.push_back(17);
    el_20_1.push_back(19);
    EList<int> el_20_2;
    el_20_2.push_back(31);
    el_20_2.push_back(37);
    el_20_2.push_back(41);
    el_20_2.push_back(43);
    el_20_2.push_back(47);
    el_20_2 = std::move(el_20_1);

    // contains(const value_type&)
    EList<int> el_21;
    el_21.push_back(53);
    el_21.push_back(59);
    el_21.push_back(61);
    el_21.push_back(67);
    el_21.push_back(71);
    bool r_21_1 = el_21.contains(67);
    bool r_21_2 = el_21.contains(73);

    // find(const value_type&)
    EList<int> el_22;
    el_22.push_back(2);
    el_22.push_back(3);
    el_22.push_back(5);
    el_22.push_back(7);
    EList<int>::iterator it_22_1 = el_22.find(7);



    return 0;
}

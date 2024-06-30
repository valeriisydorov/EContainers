#include "EVector.h"
#include <string>


int main() {
    // EVector(), push_back(const value_type& value), push_back(value_type&& value), reserve(size_type new_cap), size(), capacity()
    std::string s_1_1("Euclid");
    std::string s_1_2("Diophantus");
    std::string s_1_3("Apollonius");
    std::string s_1_4("Archimedes");
    EVector<std::string> ev_1;
    ev_1.push_back(s_1_1);
    ev_1.push_back(s_1_2);
    ev_1.push_back(std::move(s_1_3));
    ev_1.push_back(std::move(s_1_4));
    ev_1.reserve(8);
    std::size_t i_1_1 = ev_1.size();
    std::size_t i_1_2 = ev_1.capacity();

    // EVector(size_type count, value_type& value), resize(size_type count)
    std::string s_2("Archimedes");
    EVector<std::string> ev_2(2, s_2);
    ev_2.resize(1);
    ev_2.resize(4);

    // operator[](size_type pos)
    std::string s_3_1("Grigori Perelman");
    std::string s_3_2("Terence Tao");
    std::string s_3_3("David Mumford");
    EVector<std::string> ev_3;
    ev_3.push_back(s_3_1);
    ev_3.push_back(s_3_2);
    ev_3[1] = s_3_3;

    // begin()
    std::string s_4_1("Grigori Perelman");
    std::string s_4_2("Terence Tao");
    std::string s_4_3("David Mumford");
    EVector<std::string> ev_4;
    ev_4.push_back(s_4_1);
    ev_4.push_back(s_4_2);
    EVector<std::string>::iterator it_4 = ev_4.begin();
    ++it_4;
    *it_4 = s_4_3;

    // end()
    std::string s_5_1("Grigori Perelman");
    std::string s_5_2("Terence Tao");
    std::string s_5_3("David Mumford");
    EVector<std::string> ev_5;
    ev_5.push_back(s_5_1);
    ev_5.push_back(s_5_2);
    EVector<std::string>::iterator it_5 = ev_5.end();
    --it_5;
    *it_5 = s_5_3;



    return 0;
}

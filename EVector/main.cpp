#include "EVector.h"
#include <string>


int main() {
    // EVector(), push_back(const value_type& value), push_back(value_type&& value), reserve(size_type new_cap), size(), capacity()
    EVector<std::string> ev_1;
    std::string s_1_1("Euclid");
    std::string s_1_2("Diophantus");
    std::string s_1_3("Apollonius");
    std::string s_1_4("Archimedes");
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



    return 0;
}

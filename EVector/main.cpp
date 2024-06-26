#include "EVector.h"
#include "EString.h"


int main() {
    // EVector(), push_back(const value_type& value), push_back(value_type&& value), reserve(size_type new_cap), size(), capacity()
    EVector<EString> ev_1;
    EString es_1_1("Euclid");
    EString es_1_2("Diophantus");
    EString es_1_3("Archimedes");
    EString es_1_4("Apollonius");
    ev_1.push_back(es_1_1);
    ev_1.push_back(es_1_2);
    ev_1.push_back(std::move(es_1_3));
    ev_1.push_back(std::move(es_1_4));
    ev_1.reserve(8);
    std::size_t i_1_1 = ev_1.size();
    std::size_t i_1_2 = ev_1.capacity();




    return 0;
}

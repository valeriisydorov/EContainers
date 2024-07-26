#include "ESetTest.h"
#include "ESet.h"
#include "../EString/EString.h"
#include <cassert>


void ESetTest() {

    // insert(const key_type& key, bool* is_in_set = nullptr), begin()
    EString es_1_1("Thomas H. Cormen");
    EString es_1_2("Charles E. Leiserson");
    EString es_1_3("Ronald L. Rivest");
    EString es_1_4("Clifford Stein");
    ESet<EString> eset_1;
    eset_1.insert(es_1_1);
    eset_1.insert(es_1_2);
    eset_1.insert(es_1_3);
    eset_1.insert(es_1_4);
    bool is_in_1 = false;
    eset_1.insert(es_1_4, &is_in_1);
    assert(is_in_1 == true);
    assert(eset_1.size() == 4);
    ESet<EString>::iterator it_1_1 = eset_1.begin();
    assert(*it_1_1 == es_1_2);

    // find(const key_type& key)
    EString es_2_1("Thomas H. Cormen");
    EString es_2_2("Charles E. Leiserson");
    EString es_2_3("Ronald L. Rivest");
    EString es_2_4("Clifford Stein");
    ESet<EString> eset_2;
    eset_2.insert(es_2_1);
    eset_2.insert(es_2_2);
    eset_2.insert(es_2_3);
    ESet<EString>::iterator it_2_1 = eset_2.find(es_2_2);
    assert(*it_2_1 == es_2_2);


}
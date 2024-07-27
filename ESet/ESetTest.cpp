#include "ESetTest.h"
#include "ESet.h"
#include "../EString/EString.h"
#include <cassert>


void ESetTest() {

    // insert(const key_type& key, bool* is_in_set = nullptr), begin(), end()
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
    ESet<EString>::iterator it_1_2 = eset_1.end();
    assert(*it_1_1 == es_1_2);
    assert(it_1_1 != it_1_2);

    // empty(), find(const key_type& key), contains(const key_type& key)
    EString es_2_1("Thomas H. Cormen");
    EString es_2_2("Charles E. Leiserson");
    EString es_2_3("Ronald L. Rivest");
    EString es_2_4("Clifford Stein");
    ESet<EString> eset_2;
    assert(eset_2.empty() == true);
    eset_2.insert(es_2_1);
    eset_2.insert(es_2_2);
    eset_2.insert(es_2_3);
    assert(eset_2.empty() == false);
    ESet<EString>::iterator it_2_1 = eset_2.find(es_2_2);
    ESet<EString>::iterator it_2_2 = eset_2.find(es_2_4);
    assert(*it_2_1 == es_2_2);
    assert(it_2_2 == eset_2.end());
    assert(eset_2.contains(es_2_2) == true);
    assert(eset_2.contains(es_2_4) == false);



}
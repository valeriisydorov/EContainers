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

    // remove(const key_type& key)
    EString es_3_1("Edsger W. Dijkstra");
    EString es_3_2("David Gries");
    EString es_3_3("Donald E. Knuth");
    EString es_3_4("Niklaus Wirth");
    EString es_3_5("Jon Bentley");
    EString es_3_6("Henry S. Warren, Jr.");
    EString es_3_7("Daniel Mier Gusfield");
    EString es_3_8("Thomas H. Cormen");
    EString es_3_9("Charles E. Leiserson");
    EString es_3_10("Ronald L. Rivest");
    EString es_3_11("Clifford Stein");
    // remove leaf node
    ESet<EString> eset_3_1;
    eset_3_1.insert(es_3_1);
    eset_3_1.insert(es_3_2);
    eset_3_1.insert(es_3_3);
    assert(eset_3_1.remove(es_3_3) == 1);
    assert(eset_3_1.find(es_3_3) == eset_3_1.end());
    // remove one-child node
    ESet<EString> eset_3_2;
    eset_3_2.insert(es_3_4);
    eset_3_2.insert(es_3_5);
    assert(eset_3_2.remove(es_3_4) == 1);
    assert(eset_3_2.find(es_3_4) == eset_3_2.end());
    assert(eset_3_2.find(es_3_5) != eset_3_2.end());
    // remove two-child node
    ESet<EString> eset_3_3;
    eset_3_3.insert(es_3_6);
    eset_3_3.insert(es_3_7);
    eset_3_3.insert(es_3_8);
    assert(eset_3_3.remove(es_3_6) == 1);
    assert(eset_3_3.find(es_3_6) == eset_3_3.end());
    assert(eset_3_3.find(es_3_7) != eset_3_3.end());
    assert(eset_3_3.find(es_3_8) != eset_3_3.end());
    // remove root node
    ESet<EString> eset_3_4;
    eset_3_4.insert(es_3_9);
    assert(eset_3_4.remove(es_3_9) == 1);
    assert(eset_3_4.empty() == true);
    // remove non-exist node
    ESet<EString> eset_3_5;
    eset_3_5.insert(es_3_10);
    assert(eset_3_5.remove(es_3_11) == 0);


}
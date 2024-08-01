#include "ESetTest.h"
#include "ESet.h"
#include "../EString/EString.h"
#include <cassert>
#include <utility>


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

    // is_empty(), find(const key_type& key), contains(const key_type& key)
    EString es_2_1("Thomas H. Cormen");
    EString es_2_2("Charles E. Leiserson");
    EString es_2_3("Ronald L. Rivest");
    EString es_2_4("Clifford Stein");
    ESet<EString> eset_2;
    assert(eset_2.is_empty() == true);
    eset_2.insert(es_2_1);
    eset_2.insert(es_2_2);
    eset_2.insert(es_2_3);
    assert(eset_2.is_empty() == false);
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
    EString es_3_7("Daniel Gusfield");
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
    assert(eset_3_4.is_empty() == true);
    // remove non-exist node
    ESet<EString> eset_3_5;
    eset_3_5.insert(es_3_10);
    assert(eset_3_5.remove(es_3_11) == 0);

    // remove_at(iterator pos)
    EString es_4_1("Edsger W. Dijkstra");
    EString es_4_2("David Gries");
    EString es_4_3("Donald E. Knuth");
    EString es_4_4("Niklaus Wirth");
    EString es_4_5("Jon Bentley");
    EString es_4_6("Henry S. Warren, Jr.");
    EString es_4_7("Daniel Gusfield");
    EString es_4_8("Thomas H. Cormen");
    EString es_4_9("Charles E. Leiserson");
    EString es_4_10("Ronald L. Rivest");
    EString es_4_11("Clifford Stein");
    ESet<EString> eset_4;
    eset_4.insert(es_4_1);
    eset_4.insert(es_4_2);
    eset_4.insert(es_4_3);
    eset_4.insert(es_4_4);
    eset_4.insert(es_4_5);
    eset_4.insert(es_4_6);
    eset_4.insert(es_4_7);
    eset_4.insert(es_4_8);
    eset_4.insert(es_4_9);
    eset_4.insert(es_4_10);
    eset_4.insert(es_4_11);
    ESet<EString>::iterator it_4_1 = eset_4.begin();
    ++it_4_1;
    assert(*it_4_1 == es_4_11);
    ++it_4_1;
    assert(*it_4_1 == es_4_7);
    ++it_4_1;
    assert(*it_4_1 == es_4_2);
    ESet<EString>::iterator it_4_2 = eset_4.remove_at(it_4_1);
    assert(eset_4.size() == 10);
    assert(*it_4_2 == es_4_3);
    
    // clear()
    EString es_5_1("Edsger W. Dijkstra");
    EString es_5_2("David Gries");
    EString es_5_3("Donald E. Knuth");
    EString es_5_4("Niklaus Wirth");
    EString es_5_5("Jon Bentley");
    EString es_5_6("Henry S. Warren, Jr.");
    EString es_5_7("Daniel Gusfield");
    EString es_5_8("Thomas H. Cormen");
    EString es_5_9("Charles E. Leiserson");
    EString es_5_10("Ronald L. Rivest");
    EString es_5_11("Clifford Stein");
    ESet<EString> eset_5;
    eset_5.insert(es_5_1);
    eset_5.insert(es_5_2);
    eset_5.insert(es_5_3);
    eset_5.insert(es_5_4);
    eset_5.insert(es_5_5);
    eset_5.insert(es_5_6);
    eset_5.insert(es_5_7);
    eset_5.insert(es_5_8);
    eset_5.insert(es_5_9);
    eset_5.insert(es_5_10);
    eset_5.insert(es_5_11);
    eset_5.clear();
    assert(eset_5.is_empty() == true);

    // ESet(const ESet& other)
    EString es_6_1("Edsger W. Dijkstra");
    EString es_6_2("David Gries");
    EString es_6_3("Donald E. Knuth");
    EString es_6_4("Niklaus Wirth");
    EString es_6_5("Jon Bentley");
    EString es_6_6("Henry S. Warren, Jr.");
    EString es_6_7("Daniel Gusfield");
    EString es_6_8("Thomas H. Cormen");
    EString es_6_9("Charles E. Leiserson");
    EString es_6_10("Ronald L. Rivest");
    EString es_6_11("Clifford Stein");
    ESet<EString> eset_6_1;
    eset_6_1.insert(es_6_1);
    eset_6_1.insert(es_6_2);
    eset_6_1.insert(es_6_3);
    eset_6_1.insert(es_6_4);
    eset_6_1.insert(es_6_5);
    eset_6_1.insert(es_6_6);
    eset_6_1.insert(es_6_7);
    eset_6_1.insert(es_6_8);
    eset_6_1.insert(es_6_9);
    eset_6_1.insert(es_6_10);
    eset_6_1.insert(es_6_11);
    ESet<EString> eset_6_2(eset_6_1);
    assert(eset_6_1.size() == eset_6_2.size());
    ESet<EString>::iterator it_6_1 = eset_6_1.begin();
    ESet<EString>::iterator it_6_2 = eset_6_2.begin();
    while (it_6_1 != eset_6_1.end() && it_6_2 != eset_6_2.end()) {
        assert(*it_6_1 == *it_6_2);
        ++it_6_1;
        ++it_6_2;
    }
    assert(it_6_1 == eset_6_1.end() && it_6_2 == eset_6_2.end());

    // operator=(const ESet& rhs)
    EString es_7_1("Edsger W. Dijkstra");
    EString es_7_2("David Gries");
    EString es_7_3("Donald E. Knuth");
    EString es_7_4("Niklaus Wirth");
    EString es_7_5("Jon Bentley");
    EString es_7_6("Henry S. Warren, Jr.");
    EString es_7_7("Daniel Gusfield");
    EString es_7_8("Thomas H. Cormen");
    EString es_7_9("Charles E. Leiserson");
    EString es_7_10("Ronald L. Rivest");
    EString es_7_11("Clifford Stein");
    ESet<EString> eset_7_1;
    eset_7_1.insert(es_7_1);
    eset_7_1.insert(es_7_2);
    eset_7_1.insert(es_7_3);
    eset_7_1.insert(es_7_4);
    eset_7_1.insert(es_7_5);
    eset_7_1.insert(es_7_6);
    eset_7_1.insert(es_7_7);
    eset_7_1.insert(es_7_8);
    eset_7_1.insert(es_7_9);
    eset_7_1.insert(es_7_10);
    eset_7_1.insert(es_7_11);
    ESet<EString> eset_7_2 = eset_7_1;
    assert(eset_7_1.size() == eset_7_2.size());
    ESet<EString>::iterator it_7_1 = eset_7_1.begin();
    ESet<EString>::iterator it_7_2 = eset_7_2.begin();
    while (it_7_1 != eset_7_1.end() && it_7_2 != eset_7_2.end()) {
        assert(*it_7_1 == *it_7_2);
        ++it_7_1;
        ++it_7_2;
    }
    assert(it_7_1 == eset_7_1.end() && it_7_2 == eset_7_2.end());

    // ESet(ESet&& other)
    EString es_8_1("Edsger W. Dijkstra");
    EString es_8_2("David Gries");
    EString es_8_3("Donald E. Knuth");
    EString es_8_4("Niklaus Wirth");
    EString es_8_5("Jon Bentley");
    EString es_8_6("Henry S. Warren, Jr.");
    EString es_8_7("Daniel Gusfield");
    EString es_8_8("Thomas H. Cormen");
    EString es_8_9("Charles E. Leiserson");
    EString es_8_10("Ronald L. Rivest");
    EString es_8_11("Clifford Stein");
    ESet<EString> eset_8_1;
    eset_8_1.insert(es_8_1);
    eset_8_1.insert(es_8_2);
    eset_8_1.insert(es_8_3);
    eset_8_1.insert(es_8_4);
    eset_8_1.insert(es_8_5);
    eset_8_1.insert(es_8_6);
    eset_8_1.insert(es_8_7);
    eset_8_1.insert(es_8_8);
    eset_8_1.insert(es_8_9);
    eset_8_1.insert(es_8_10);
    eset_8_1.insert(es_8_11);
    ESet<EString> eset_8_2(std::move(eset_8_1));
    assert(eset_8_1.is_empty() == true);
    assert(eset_8_2.size() == 11);

    // operator=(ESet&& rhs)
    EString es_9_1("Edsger W. Dijkstra");
    EString es_9_2("David Gries");
    EString es_9_3("Donald E. Knuth");
    EString es_9_4("Niklaus Wirth");
    EString es_9_5("Jon Bentley");
    EString es_9_6("Henry S. Warren, Jr.");
    EString es_9_7("Daniel Gusfield");
    EString es_9_8("Thomas H. Cormen");
    EString es_9_9("Charles E. Leiserson");
    EString es_9_10("Ronald L. Rivest");
    EString es_9_11("Clifford Stein");
    ESet<EString> eset_9_1;
    eset_9_1.insert(es_9_1);
    eset_9_1.insert(es_9_2);
    eset_9_1.insert(es_9_3);
    eset_9_1.insert(es_9_4);
    eset_9_1.insert(es_9_5);
    eset_9_1.insert(es_9_6);
    eset_9_1.insert(es_9_7);
    eset_9_1.insert(es_9_8);
    eset_9_1.insert(es_9_9);
    eset_9_1.insert(es_9_10);
    eset_9_1.insert(es_9_11);
    ESet<EString> eset_9_2 = std::move(eset_9_1);
    assert(eset_9_1.is_empty() == true);
    assert(eset_9_2.size() == 11);


}
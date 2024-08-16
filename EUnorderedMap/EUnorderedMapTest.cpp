#include "EUnorderedMapTest.h"
#include "EUnorderedMap.h"
#include <cassert>
#include "../EString/EString.h"
#include "EStringHash.h"


void EUnorderedMapTest()
{
    // EUnorderedMap(), begin(), end(), insert(key_type key, mapped_type value, bool* is_in_map)
    EUnorderedMap<EString, EString> eum_1;
    assert(eum_1.size() == 0);
    assert(eum_1.begin() == eum_1.end());
    EString es_1_1_1("Edsger W. Dijkstra");
    EString es_1_1_2("A Discipline of Programming");
    EUnorderedMap<EString, EString>::iterator it_1_1 = eum_1.insert(es_1_1_1, es_1_1_2);
    EUnorderedMap<EString, EString>::iterator it_1_2 = eum_1.begin();
    assert(eum_1.size() == 1);
    assert(it_1_2 != eum_1.end());
    assert(it_1_2 == it_1_1);
    assert(it_1_1.get_key() == "Edsger W. Dijkstra");
    assert(it_1_1.get_value() == "A Discipline of Programming");
    EString es_1_2_1("Donald E. Knuth");
    EString es_1_2_2("Stable Marriage and Its Relation to Other Combinatorial Problems");
    EUnorderedMap<EString, EString>::iterator it_1_3 = eum_1.insert(es_1_2_1, es_1_2_2);
    assert(eum_1.size() == 2);
    assert(it_1_3.get_key() == "Donald E. Knuth");
    assert(it_1_3.get_value() == "Stable Marriage and Its Relation to Other Combinatorial Problems");
    EString es_1_3_1("Donald E. Knuth");
    EString es_1_3_2("The Art of Computer Programming");
    EUnorderedMap<EString, EString>::iterator it_1_4 = eum_1.insert(es_1_3_1, es_1_3_2);
    assert(eum_1.size() == 2);
    assert(it_1_4.get_key() == "Donald E. Knuth");
    assert(it_1_4.get_value() == "The Art of Computer Programming");

    // find_value(const key_type& key)
    EString es_2_1_1("Edsger W. Dijkstra");
    EString es_2_1_2("A Discipline of Programming");
    EString es_2_2_1("Niklaus Wirth");
    EString es_2_2_2("Algorithms + Data Structures = Programs");
    EString es_2_3_1("Donald E. Knuth");
    EString es_2_3_2("The Art of Computer Programming");
    EString es_2_4_1("Jon Bentley");
    EString es_2_4_2("Programming Pearls");
    EUnorderedMap<EString, EString> eum_2;
    eum_2.insert(es_2_1_1, es_2_1_2);
    eum_2.insert(es_2_2_1, es_2_2_2);
    eum_2.insert(es_2_3_1, es_2_3_2);
    EUnorderedMap<EString, EString>::mapped_type* p_2_1 = eum_2.find_value(es_2_2_1);
    EUnorderedMap<EString, EString>::mapped_type* p_2_2 = eum_2.find_value(es_2_4_1);
    assert(*p_2_1 == "Algorithms + Data Structures = Programs");
    assert(p_2_2 == nullptr);

    // remove_by_key(const key_type& key)
    EString es_3_1_1("Edsger W. Dijkstra");
    EString es_3_1_2("A Discipline of Programming");
    EString es_3_2_1("Niklaus Wirth");
    EString es_3_2_2("Algorithms + Data Structures = Programs");
    EString es_3_3_1("Donald E. Knuth");
    EString es_3_3_2("The Art of Computer Programming");
    EString es_3_4_1("Jon Bentley");
    EString es_3_4_2("Programming Pearls");
    EUnorderedMap<EString, EString> eum_3;
    eum_3.insert(es_3_1_1, es_3_1_2);
    eum_3.insert(es_3_2_1, es_3_2_2);
    eum_3.insert(es_3_3_1, es_3_3_2);
    eum_3.insert(es_3_4_1, es_3_4_2);
    EUnorderedMap<EString, EString>::mapped_type* p_3_1 = eum_3.find_value(es_3_2_1);
    assert(*p_3_1 == "Algorithms + Data Structures = Programs");
    assert(eum_3.remove_by_key(es_3_2_1) == 1);
    assert(eum_3.size() == 3);
    EUnorderedMap<EString, EString>::mapped_type* p_3_2 = eum_3.find_value(es_3_2_1);
    assert(p_3_2 == nullptr);
    assert(eum_3.remove_by_key(es_3_2_1) == 0);

    // find_key(const mapped_type& value)
    EString es_4_1_1("Edsger W. Dijkstra");
    EString es_4_1_2("A Discipline of Programming");
    EString es_4_2_1("Niklaus Wirth");
    EString es_4_2_2("Algorithms + Data Structures = Programs");
    EString es_4_3_1("Donald E. Knuth");
    EString es_4_3_2("The Art of Computer Programming");
    EString es_4_4_1("Jon Bentley");
    EString es_4_4_2("Programming Pearls");
    EUnorderedMap<EString, EString> eum_4;
    eum_4.insert(es_4_1_1, es_4_1_2);
    eum_4.insert(es_4_2_1, es_4_2_2);
    eum_4.insert(es_4_3_1, es_4_3_2);
    const EUnorderedMap<EString, EString>::key_type* p_4_1 = eum_4.find_key(es_4_3_2);
    const EUnorderedMap<EString, EString>::key_type* p_4_2 = eum_4.find_key(es_4_4_2);
    assert(*p_4_1 == "Donald E. Knuth");
    assert(p_4_2 == nullptr);

    // remove_by_value(const mapped_type& value)
    EString es_5_1_1("Edsger W. Dijkstra");
    EString es_5_1_2("A Discipline of Programming");
    EString es_5_2_1("Niklaus Wirth");
    EString es_5_2_2("Algorithms + Data Structures = Programs");
    EString es_5_3_1("Donald E. Knuth");
    EString es_5_3_2("The Art of Computer Programming");
    EString es_5_4_1("Jon Bentley");
    EString es_5_4_2("Programming Pearls");
    EUnorderedMap<EString, EString> eum_5;
    eum_5.insert(es_5_1_1, es_5_1_2);
    eum_5.insert(es_5_2_1, es_5_2_2);
    eum_5.insert(es_5_3_1, es_5_3_2);
    eum_5.insert(es_5_4_1, es_5_4_2);
    EUnorderedMap<EString, EString>::iterator it_5 = eum_5.remove_by_value(es_5_2_2);
    assert(eum_5.size() == 3);
    assert(it_5.get_key() == "Donald E. Knuth" && it_5.get_value() == "The Art of Computer Programming");


}
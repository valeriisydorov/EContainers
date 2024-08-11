#include "EVectorTest.h"
#include "EVector.h"
#include "../EString/EString.h"
#include "NStandard.h"
#include <cassert>


void EVectorTest() {
    // EVector(), push_back(const value_type& value), push_back(value_type&& value), reserve(size_type new_cap)
    EString es_1_1("Euclid");
    EString es_1_2("Diophantus");
    EString es_1_3("Apollonius");
    EString es_1_4("Archimedes");
    EVector<EString> ev_1_1;
    ev_1_1.push_back(es_1_1);
    ev_1_1.push_back(es_1_2);
    ev_1_1.push_back(std::move(es_1_3));
    ev_1_1.push_back(std::move(es_1_4));
    assert(ev_1_1[0] == es_1_1);
    assert(ev_1_1[1] == es_1_2);
    assert(ev_1_1[2] == EString("Apollonius"));
    assert(ev_1_1[3] == EString("Archimedes"));
    assert(ev_1_1.size() == 4);
    assert(ev_1_1.capacity() >= 4);
    ev_1_1.reserve(8);
    assert(ev_1_1.capacity() >= 8);

    NStandard<EString> ns_1_1("Euclid");
    NStandard<EString> ns_1_2("Diophantus");
    NStandard<EString> ns_1_3("Apollonius");
    NStandard<EString> ns_1_4("Archimedes");
    EVector<NStandard<EString>> ev_1_2;
    ev_1_2.push_back(ns_1_1);
    ev_1_2.push_back(ns_1_2);
    ev_1_2.push_back(std::move(ns_1_3));
    ev_1_2.push_back(std::move(ns_1_4));
    assert(ev_1_2[0].get_value() == ns_1_1.get_value());
    assert(ev_1_2[1].get_value() == ns_1_2.get_value());
    assert(ev_1_2[2].get_value() == EString("Apollonius"));
    assert(ev_1_2[3].get_value() == EString("Archimedes"));
    assert(ev_1_2.size() == 4);
    assert(ev_1_2.capacity() >= 4);
    ev_1_2.reserve(8);
    assert(ev_1_2.capacity() >= 8);

    // EVector(size_type count, value_type& value), resize(size_type count)
    EString es_2("Archimedes");
    EVector<EString> ev_2_1(2, es_2);
    assert(ev_2_1[0] == es_2);
    assert(ev_2_1[1] == es_2);
    assert(ev_2_1.size() == 2);
    ev_2_1.resize(1);
    assert(ev_2_1.size() == 1);
    ev_2_1.resize(4);
    assert(ev_2_1[1].empty() == true);
    assert(ev_2_1[2].empty() == true);
    assert(ev_2_1[3].empty() == true);
    assert(ev_2_1.size() == 4);

    NStandard<EString> ns_2("Archimedes");
    EVector<NStandard<EString>> ev_2_2(2, ns_2);
    assert(ev_2_2[0].get_value() == EString("Archimedes"));
    assert(ev_2_2[1].get_value() == EString("Archimedes"));
    assert(ev_2_2.size() == 2);
    ev_2_2.resize(1);
    assert(ev_2_2.size() == 1);
    ev_2_2.resize(4);
    assert(ev_2_2.size() == 4);

    // operator[](size_type pos)
    EString es_3_1("Grigori Perelman");
    EString es_3_2("Terence Tao");
    EString es_3_3("David Mumford");
    EVector<EString> ev_3_1;
    ev_3_1.push_back(es_3_1);
    ev_3_1.push_back(es_3_2);
    ev_3_1[1] = es_3_3;
    assert(ev_3_1[1] == es_3_3);

    NStandard<EString> ns_3_1("Grigori Perelman");
    NStandard<EString> ns_3_2("Terence Tao");
    NStandard<EString> ns_3_3("David Mumford");
    EVector<NStandard<EString>> ev_3_2;
    ev_3_2.push_back(ns_3_1);
    ev_3_2.push_back(ns_3_2);
    ev_3_2[1] = ns_3_3;
    assert(ev_3_2[1].get_value() == ns_3_3.get_value());

    // begin()
    EString es_4_1("Grigori Perelman");
    EString es_4_2("Terence Tao");
    EString es_4_3("David Mumford");
    EVector<EString> ev_4_1;
    ev_4_1.push_back(es_4_1);
    ev_4_1.push_back(es_4_2);
    EVector<EString>::iterator it_4_1 = ev_4_1.begin();
    ++it_4_1;
    assert(*it_4_1 == es_4_2);
    *it_4_1 = es_4_3;
    assert(*it_4_1 == es_4_3);

    NStandard<EString> ns_4_1("Grigori Perelman");
    NStandard<EString> ns_4_2("Terence Tao");
    NStandard<EString> ns_4_3("David Mumford");
    EVector<NStandard<EString>> ev_4_2;
    ev_4_2.push_back(ns_4_1);
    ev_4_2.push_back(ns_4_2);
    EVector<NStandard<EString>>::iterator it_4_2 = ev_4_2.begin();
    ++it_4_2;
    assert((*it_4_2).get_value() == ns_4_2.get_value());
    *it_4_2 = ns_4_3;
    assert((*it_4_2).get_value() == ns_4_3.get_value());

    // end()
    EString es_5_1("Grigori Perelman");
    EString es_5_2("Terence Tao");
    EString es_5_3("David Mumford");
    EVector<EString> ev_5_1;
    ev_5_1.push_back(es_5_1);
    ev_5_1.push_back(es_5_2);
    EVector<EString>::iterator it_5_1 = ev_5_1.end();
    --it_5_1;
    assert(*it_5_1 == es_5_2);
    *it_5_1 = es_5_3;
    assert(*it_5_1 == es_5_3);

    NStandard<EString> ns_5_1("Grigori Perelman");
    NStandard<EString> ns_5_2("Terence Tao");
    NStandard<EString> ns_5_3("David Mumford");
    EVector<NStandard<EString>> ev_5_2;
    ev_5_2.push_back(ns_5_1);
    ev_5_2.push_back(ns_5_2);
    EVector<NStandard<EString>>::iterator it_5_2 = ev_5_2.end();
    --it_5_2;
    assert((*it_5_2).get_value() == ns_5_2.get_value());
    *it_5_2 = ns_5_3;
    assert((*it_5_2).get_value() == ns_5_3.get_value());

    // cbegin()
    EString es_6_1("Jakob Bernoulli");
    EString es_6_2("Johann Bernoulli");
    EString es_6_3("Daniel Bernoulli");
    EVector<EString> ev_6;
    ev_6.push_back(es_6_1);
    ev_6.push_back(es_6_2);
    EVector<EString>::const_iterator it_6 = ev_6.cbegin();
    ++it_6;
    assert(*it_6 == es_6_2);
    // *it_6 = es_6_3;

    // cend()
    EString es_7_1("Jakob Bernoulli");
    EString es_7_2("Johann Bernoulli");
    EString es_7_3("Daniel Bernoulli");
    EVector<EString> ev_7;
    ev_7.push_back(es_7_1);
    ev_7.push_back(es_7_2);
    EVector<EString>::const_iterator it_7 = ev_7.cend();
    --it_7;
    assert(*it_7 == es_7_2);
    // *it_7 = es_7_3;

    // insert(size_type pos, const value_type& value)
    EString es_8_1("Jakob Bernoulli");
    EString es_8_2("Johann Bernoulli");
    EString es_8_3("Daniel Bernoulli");
    EVector<EString> ev_8_1;
    ev_8_1.push_back(es_8_1);
    ev_8_1.push_back(es_8_3);
    assert(ev_8_1.insert(1, es_8_2) == 1);
    assert(ev_8_1[1] == es_8_2);
    assert(ev_8_1[2] == es_8_3);

    NStandard<EString> ns_8_1("Jakob Bernoulli");
    NStandard<EString> ns_8_2("Johann Bernoulli");
    NStandard<EString> ns_8_3("Daniel Bernoulli");
    EVector<NStandard<EString>> ev_8_2;
    ev_8_2.push_back(ns_8_1);
    ev_8_2.push_back(ns_8_3);
    assert(ev_8_2.insert(1, ns_8_2) == 1);
    assert(ev_8_2[1].get_value() == ns_8_2.get_value());
    assert(ev_8_2[2].get_value() == ns_8_3.get_value());

    // insert(const_iterator it, const value_type& value)
    EString es_9_1("Marshall Hall");
    EString es_9_2("Donald Knuth");
    EString es_9_3("Robert Sedgewick");
    EVector<EString> ev_9_1;
    ev_9_1.push_back(es_9_1);
    ev_9_1.push_back(es_9_3);
    EVector<EString>::const_iterator it_9_1 = ev_9_1.cbegin();
    ++it_9_1;
    ev_9_1.insert(it_9_1, es_9_2);
    assert(ev_9_1[1] == es_9_2);
    assert(ev_9_1[2] == es_9_3);

    NStandard<EString> ns_9_1("Marshall Hall");
    NStandard<EString> ns_9_2("Donald Knuth");
    NStandard<EString> ns_9_3("Robert Sedgewick");
    EVector<NStandard<EString>> ev_9_2;
    ev_9_2.push_back(ns_9_1);
    ev_9_2.push_back(ns_9_3);
    EVector<NStandard<EString>>::const_iterator it_9_2 = ev_9_2.cbegin();
    ++it_9_2;
    ev_9_2.insert(it_9_2, ns_9_2);
    assert(ev_9_2[1].get_value() == ns_9_2.get_value());
    assert(ev_9_2[2].get_value() == ns_9_3.get_value());

    // erase(size_type pos)
    EString es_10_1("Marshall Hall");
    EString es_10_2("Donald Knuth");
    EString es_10_3("Robert Sedgewick");
    EVector<EString> ev_10_1;
    ev_10_1.push_back(es_10_1);
    ev_10_1.push_back(es_10_2);
    ev_10_1.push_back(es_10_3);
    assert(ev_10_1.erase(0) == 0);
    assert(ev_10_1[0] == es_10_2);
    assert(ev_10_1[1] == es_10_3);
    assert(ev_10_1.size() == 2);

    NStandard<EString> ns_10_1("Marshall Hall");
    NStandard<EString> ns_10_2("Donald Knuth");
    NStandard<EString> ns_10_3("Robert Sedgewick");
    EVector<NStandard<EString>> ev_10_2;
    ev_10_2.push_back(ns_10_1);
    ev_10_2.push_back(ns_10_2);
    ev_10_2.push_back(ns_10_3);
    assert(ev_10_2.erase(0) == 0);
    assert(ev_10_2[0].get_value() == ns_10_2.get_value());
    assert(ev_10_2[1].get_value() == ns_10_3.get_value());
    assert(ev_10_2.size() == 2);

    // erase(value_type& value)
    EString es_11_1("Marshall Hall");
    EString es_11_2("Donald Knuth");
    EString es_11_3("Robert Sedgewick");
    EVector<EString> ev_11;
    ev_11.push_back(es_11_1);
    ev_11.push_back(es_11_2);
    ev_11.push_back(es_11_3);
    ev_11.erase(es_11_1);
    assert(ev_11[0] == es_11_2);
    assert(ev_11[1] == es_11_3);
    assert(ev_11.size() == 2);

    // EVector(const EVector& other)
    EString es_12_1("Isaac Newton");
    EString es_12_2("Gottfried Wilhelm Leibniz");
    EString es_12_3("Leonhard Euler");
    EString es_12_4("Augustin-Louis Cauchy");
    EVector<EString> ev_12_1_1;
    ev_12_1_1.push_back(es_12_1);
    ev_12_1_1.push_back(es_12_2);
    ev_12_1_1.push_back(es_12_3);
    ev_12_1_1.push_back(es_12_4);
    EVector<EString> ev_12_1_2(ev_12_1_1);
    assert(ev_12_1_2[0] == es_12_1);
    assert(ev_12_1_2[1] == es_12_2);
    assert(ev_12_1_2[2] == es_12_3);
    assert(ev_12_1_2[3] == es_12_4);

    NStandard<EString> ns_12_1("Isaac Newton");
    NStandard<EString> ns_12_2("Gottfried Wilhelm Leibniz");
    NStandard<EString> ns_12_3("Leonhard Euler");
    NStandard<EString> ns_12_4("Augustin-Louis Cauchy");
    EVector<NStandard<EString>> ev_12_2_1;
    ev_12_2_1.push_back(ns_12_1);
    ev_12_2_1.push_back(ns_12_2);
    ev_12_2_1.push_back(ns_12_3);
    ev_12_2_1.push_back(ns_12_4);
    EVector<NStandard<EString>> ev_12_2_2(ev_12_2_1);
    assert(ev_12_2_2[0].get_value() == ns_12_1.get_value());
    assert(ev_12_2_2[1].get_value() == ns_12_2.get_value());
    assert(ev_12_2_2[2].get_value() == ns_12_3.get_value());
    assert(ev_12_2_2[3].get_value() == ns_12_4.get_value());

    // operator=(const EVector& rhs)
    EString es_13_1("Isaac Newton");
    EString es_13_2("Gottfried Wilhelm Leibniz");
    EString es_13_3("Leonhard Euler");
    EString es_13_4("Augustin-Louis Cauchy");
    EVector<EString> ev_13_1_1;
    EVector<EString> ev_13_1_2;
    ev_13_1_1.push_back(es_13_1);
    ev_13_1_1.push_back(es_13_2);
    ev_13_1_2.push_back(es_13_3);
    ev_13_1_2.push_back(es_13_4);
    ev_13_1_1 = ev_13_1_2;
    assert(ev_13_1_1[0] == es_13_3);
    assert(ev_13_1_1[1] == es_13_4);

    NStandard<EString> ns_13_1("Isaac Newton");
    NStandard<EString> ns_13_2("Gottfried Wilhelm Leibniz");
    NStandard<EString> ns_13_3("Leonhard Euler");
    NStandard<EString> ns_13_4("Augustin-Louis Cauchy");
    EVector<NStandard<EString>> ev_13_2_1;
    EVector<NStandard<EString>> ev_13_2_2;
    ev_13_2_1.push_back(ns_13_1);
    ev_13_2_1.push_back(ns_13_2);
    ev_13_2_2.push_back(ns_13_3);
    ev_13_2_2.push_back(ns_13_4);
    ev_13_2_1 = ev_13_2_2;
    assert(ev_13_2_1[0].get_value() == ns_13_3.get_value());
    assert(ev_13_2_1[1].get_value() == ns_13_4.get_value());

    // EVector(EVector&& other)
    EString es_14_1("Bernhard Riemann");
    EString es_14_2("Peter Gustav Lejeune Dirichlet");
    EString es_14_3("Georg Cantor");
    EString es_14_4("David Hilbert");
    EVector<EString> ev_14_1_1;
    ev_14_1_1.push_back(es_14_1);
    ev_14_1_1.push_back(es_14_2);
    ev_14_1_1.push_back(es_14_3);
    ev_14_1_1.push_back(es_14_4);
    EVector<EString> ev_14_1_2(std::move(ev_14_1_1));
    assert(ev_14_1_2[0] == es_14_1);
    assert(ev_14_1_2[1] == es_14_2);
    assert(ev_14_1_2[2] == es_14_3);
    assert(ev_14_1_2[3] == es_14_4);
    assert(ev_14_1_1.size() == 0);
    assert(ev_14_1_1.capacity() == 0);

    NStandard<EString> ns_14_1("Bernhard Riemann");
    NStandard<EString> ns_14_2("Peter Gustav Lejeune Dirichlet");
    NStandard<EString> ns_14_3("Georg Cantor");
    NStandard<EString> ns_14_4("David Hilbert");
    EVector<NStandard<EString>> ev_14_2_1;
    ev_14_2_1.push_back(ns_14_1);
    ev_14_2_1.push_back(ns_14_2);
    ev_14_2_1.push_back(ns_14_3);
    ev_14_2_1.push_back(ns_14_4);
    EVector<NStandard<EString>> ev_14_2_2(std::move(ev_14_2_1));
    assert(ev_14_2_2[0].get_value() == ns_14_1.get_value());
    assert(ev_14_2_2[1].get_value() == ns_14_2.get_value());
    assert(ev_14_2_2[2].get_value() == ns_14_3.get_value());
    assert(ev_14_2_2[3].get_value() == ns_14_4.get_value());
    assert(ev_14_2_1.size() == 0);
    assert(ev_14_2_1.capacity() == 0);

    // operator=(EVector&& rhs)
    EString es_15_1("Bernhard Riemann");
    EString es_15_2("Peter Gustav Lejeune Dirichlet");
    EString es_15_3("Georg Cantor");
    EString es_15_4("David Hilbert");
    EVector<EString> ev_15_1_1;
    EVector<EString> ev_15_1_2;
    ev_15_1_1.push_back(es_15_1);
    ev_15_1_1.push_back(es_15_2);
    ev_15_1_2.push_back(es_15_3);
    ev_15_1_2.push_back(es_15_4);
    ev_15_1_1 = std::move(ev_15_1_2);
    assert(ev_15_1_1[0] == es_15_3);
    assert(ev_15_1_1[1] == es_15_4);
    assert(ev_15_1_2.size() == 0);
    assert(ev_15_1_2.capacity() == 0);

    NStandard<EString> ns_15_1("Bernhard Riemann");
    NStandard<EString> ns_15_2("Peter Gustav Lejeune Dirichlet");
    NStandard<EString> ns_15_3("Georg Cantor");
    NStandard<EString> ns_15_4("David Hilbert");
    EVector<NStandard<EString>> ev_15_2_1;
    EVector<NStandard<EString>> ev_15_2_2;
    ev_15_2_1.push_back(ns_15_1);
    ev_15_2_1.push_back(ns_15_2);
    ev_15_2_2.push_back(ns_15_3);
    ev_15_2_2.push_back(ns_15_4);
    ev_15_2_1 = std::move(ev_15_2_2);
    assert(ev_15_2_1[0].get_value() == ns_15_3.get_value());
    assert(ev_15_2_1[1].get_value() == ns_15_4.get_value());
    assert(ev_15_2_2.size() == 0);
    assert(ev_15_2_2.capacity() == 0);

}
#include "EVectorTest.h"
#include "EVector.h"
#include "../EString/EString.h"
#include "NStandard.h"
#include <cassert>
#include <iostream>


void EVectorTest() {
    // EVector(), push_back(const value_type& value), push_back(value_type&& value), reserve(size_type new_cap)
    EString s_1_1("Euclid");
    EString s_1_2("Diophantus");
    EString s_1_3("Apollonius");
    EString s_1_4("Archimedes");

    EVector<EString> ev_1_1;
    ev_1_1.push_back(s_1_1);
    ev_1_1.push_back(s_1_2);
    ev_1_1.push_back(std::move(s_1_3));
    ev_1_1.push_back(std::move(s_1_4));

    assert(ev_1_1[0] == EString("Euclid"));
    assert(ev_1_1[1] == EString("Diophantus"));
    assert(ev_1_1[2] == EString("Apollonius"));
    assert(ev_1_1[3] == EString("Archimedes"));

    assert(ev_1_1.size() == 4);
    assert(ev_1_1.capacity() >= 4);

    ev_1_1.reserve(8);

    assert(ev_1_1.capacity() >= 8);

    NStandard<double> ns_1_1(2.718281828459045);
    NStandard<double> ns_1_2(3.141592653589793);

    EVector<NStandard<double>> ev_1_2;
//    ev_1_2.push_back(ns_1_1);
//    ev_1_2.push_back(ns_1_2);

    ev_1_2.reserve(8);

    // EVector(size_type count, value_type& value), resize(size_type count)
    EString s_2("Archimedes");
//    EVector<EString> ev_2(2, s_2);
//    ev_2.resize(1);
//    ev_2.resize(4);

    // operator[](size_type pos)
    EString s_3_1("Grigori Perelman");
    EString s_3_2("Terence Tao");
    EString s_3_3("David Mumford");
    EVector<EString> ev_3;
    ev_3.push_back(s_3_1);
    ev_3.push_back(s_3_2);
    ev_3[1] = s_3_3;

    // begin()
//    EString s_4_1("Grigori Perelman");
//    EString s_4_2("Terence Tao");
//    EString s_4_3("David Mumford");
//    EVector<EString> ev_4;
//    ev_4.push_back(s_4_1);
//    ev_4.push_back(s_4_2);
//    EVector<EString>::iterator it_4 = ev_4.begin();
//    ++it_4;
//    *it_4 = s_4_3;

    // end()
//    EString s_5_1("Grigori Perelman");
//    EString s_5_2("Terence Tao");
//    EString s_5_3("David Mumford");
//    EVector<EString> ev_5;
//    ev_5.push_back(s_5_1);
//    ev_5.push_back(s_5_2);
//    EVector<EString>::iterator it_5 = ev_5.end();
//    --it_5;
//    *it_5 = s_5_3;

    // cbegin()
//    EString s_6_1("Jakob Bernoulli");
//    EString s_6_2("Johann Bernoulli");
//    EString s_6_3("Daniel Bernoulli");
//    EVector<EString> ev_6;
//    ev_6.push_back(s_6_1);
//    ev_6.push_back(s_6_2);
//    EVector<EString>::const_iterator it_6 = ev_6.cbegin();
//    ++it_6;
    // *it_6 = s_6_3;

    // cend()
//    EString s_7_1("Jakob Bernoulli");
//    EString s_7_2("Johann Bernoulli");
//    EString s_7_3("Daniel Bernoulli");
//    EVector<EString> ev_7;
//    ev_7.push_back(s_7_1);
//    ev_7.push_back(s_7_2);
//    EVector<EString>::const_iterator it_7 = ev_7.cend();
//    --it_7;
    // *it_7 = s_7_3;

    // insert(size_type pos, const value_type& value)
//    EString s_8_1("Jakob Bernoulli");
//    EString s_8_2("Johann Bernoulli");
//    EString s_8_3("Daniel Bernoulli");
//    EVector<EString> ev_8;
//    ev_8.push_back(s_8_1);
//    ev_8.push_back(s_8_3);
//    ev_8.insert(1, s_8_2);

    // insert(const_iterator it, const value_type& value)
//    EString s_9_1("Marshall Hall");
//    EString s_9_2("Donald Knuth");
//    EString s_9_3("Robert Sedgewick");
//    EVector<EString> ev_9;
//    ev_9.push_back(s_9_1);
//    ev_9.push_back(s_9_3);
//    EVector<EString>::const_iterator it_9 = ev_9.cbegin();
//    ++it_9;
//    ev_9.insert(it_9, s_9_2);

    // erase(size_type pos)
//    EString s_10_1("Marshall Hall");
//    EString s_10_2("Donald Knuth");
//    EString s_10_3("Robert Sedgewick");
//    EVector<EString> ev_10;
//    ev_10.push_back(s_10_1);
//    ev_10.push_back(s_10_2);
//    ev_10.push_back(s_10_3);
//    ev_10.erase(0);

    // erase(value_type& value)
//    EString s_11_1("Marshall Hall");
//    EString s_11_2("Donald Knuth");
//    EString s_11_3("Robert Sedgewick");
//    EVector<EString> ev_11;
//    ev_11.push_back(s_11_1);
//    ev_11.push_back(s_11_2);
//    ev_11.push_back(s_11_3);
//    ev_11.erase(s_11_1);

    // EVector(const EVector& other)
//    EString s_12_1("Isaac Newton");
//    EString s_12_2("Gottfried Wilhelm Leibniz");
//    EString s_12_3("Leonhard Euler");
//    EString s_12_4("Augustin-Louis Cauchy");
//    EVector<EString> ev_12_1;
//    ev_12_1.push_back(s_12_1);
//    ev_12_1.push_back(s_12_2);
//    ev_12_1.push_back(s_12_3);
//    EVector<EString> ev_12_2(ev_12_1);

    // operator=(const EVector& rhs)
//    EString s_13_1("Isaac Newton");
//    EString s_13_2("Gottfried Wilhelm Leibniz");
//    EString s_13_3("Leonhard Euler");
//    EString s_13_4("Augustin-Louis Cauchy");
//    EVector<EString> ev_13_1;
//    EVector<EString> ev_13_2;
//    ev_13_1.push_back(s_13_1);
//    ev_13_1.push_back(s_13_2);
//    ev_13_2.push_back(s_13_3);
//    ev_13_2.push_back(s_13_4);
//    ev_13_1 = ev_13_2;

    // EVector(EVector&& other)
//    EString s_14_1("Bernhard Riemann");
//    EString s_14_2("Peter Gustav Lejeune Dirichlet");
//    EString s_14_3("Georg Cantor");
//    EString s_14_4("David Hilbert");
//    EVector<EString> ev_14_1;
//    ev_14_1.push_back(s_14_1);
//    ev_14_1.push_back(s_14_2);
//    ev_14_1.push_back(s_14_3);
//    ev_14_1.push_back(s_14_4);
//    EVector<EString> ev_14_2(std::move(ev_14_1));

    // operator=(EVector&& rhs)
//    EString s_15_1("Bernhard Riemann");
//    EString s_15_2("Peter Gustav Lejeune Dirichlet");
//    EString s_15_3("Georg Cantor");
//    EString s_15_4("David Hilbert");
//    EVector<EString> ev_15_1;
//    EVector<EString> ev_15_2;
//    ev_15_1.push_back(s_15_1);
//    ev_15_1.push_back(s_15_2);
//    ev_15_2.push_back(s_15_3);
//    ev_15_2.push_back(s_15_4);
//    ev_15_2 = ev_15_1;

}
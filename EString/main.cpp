#include <iostream>
#include <vector>
#include "EString.h"


int main() {
    // EString()
    EString es_0;

    // EString(const value_type*)
    EString es_1("Edsger Dijkstra");

    // EString(const value_type*)
    EString es_2 = "David Gries";

    // EString(const value_type*, size_type)
    EString es_3("Thomas Cormen ", 13);

    // EString(std::initializer_list<value_type>)
    EString es_4({'D', 'o', 'n', 'a', 'l', 'd', ' ', 'K', 'n', 'u', 't', 'h'});

    // EString(It, It), begin(), end()
    char arr_5[] = {'D', 'o', 'n', 'a', 'l', 'd', ' ', 'K', 'n', 'u', 't', 'h'};
    EString es_5_1(std::begin(arr_5), std::end(arr_5));
    EString es_5_2(es_5_1.begin(), es_5_1.end());

    // EString(const std::string&)
    std::string s_6("Bjarne Stroustrup");
    EString es_6(s_6);

    // EString(const EString&)
    EString es_7_1("Edsger Dijkstra");
    EString es_7_2(es_7_1);

    // operator=(const EString&)
    EString es_8_1("David Gries");
    EString es_8_2;
    es_8_2 = es_8_1;

    // EString(EString&&)
    EString es_9_1("Alexander Stepanov");
    EString es_9_2(std::move(es_9_1));

    // operator=(EString&&)
    EString es_10_1("Scott Meyers");
    EString es_10_2;
    es_10_2 = std::move(es_10_1);

    // operator=(const std::string&)
    std::string s_11("Andrei Alexandrescu");
    EString es_11;
    es_11 = s_11;

    // EString(size_type, value_type)
    EString es_12(3, 'D');

    // rbegin(), rend()
    EString es_13_1("yeltneB noJ");
    EString es_13_2(es_13_1.rbegin(), es_13_1.rend());

    // at(size_type), operator[](size_type), front(), back()
    EString es_14("?onald ?? Knut?");
    es_14.at(7) = 'E';
    es_14[8] = '.';
    es_14.front() = 'D';
    es_14.back() = 'h';

    // assign(const value_type*)
    EString es_15("Andrei Alexandrescu");
    es_15.assign("Jon Bentley");

    // assign(const value_type*, size_type)
    EString es_16;
    es_16.assign("Robert Sedgewick ", 16);

    // assign(size_type, value_type)
    EString es_17;
    es_17.assign(3, 'D');

    // assign(It, It)
    std::vector<char> v_18 = {'R', 'o', 'b', 'e', 'r', 't', ' ', 'M', 'a', 'r', 't', 'i', 'n'};
    EString es_18;
    es_18.assign(v_18.begin(), v_18.end());

    // assign(const EString&)
    EString es_19_1("Alexander Stepanov");
    EString es_19_2;
    es_19_2.assign(es_19_1);

    // assign(const EString&, size_type, size_type)
    EString es_20_1(" Charles Wetherell ");
    EString es_20_2;
    es_20_2.assign(es_20_1, 1, 17);

    // assign(EString&&)
    EString es_21_1("Stanley Lippman");
    EString es_21_2;
    es_21_2.assign(std::move(es_21_1));

    // assign(std::initializer_list<value_type>)
    EString es_22;
    es_22.assign({'D', 'o', 'n', 'a', 'l', 'd', ' ', 'K', 'n', 'u', 't', 'h'});

    // assign(const std::string&)
    std::string s_23("Alexander Stepanov");
    EString es_23;
    es_23.assign(s_23);

    // assign(const std::string&, size_type, size_type)
    std::string s_24(" Charles Wetherell ");
    EString es_24;
    es_24.assign(s_24, 1, 17);

    // insert(size_type, size_type, value_type)
    EString es_25("Stanley Liman");
    es_25.insert(10, 2, 'p');

    // insert(size_type, const value_type*)
    EString es_26("Donald Knuth");
    es_26.insert(6, " E.");

    // EString& insert(size_type, const value_type*, size_type)
    EString es_27("Edsger Dijkstra");
    es_27.insert(6, " W. ", 3);

    // insert(size_type, const const EString&)
    EString es_28_1(" B.");
    EString es_28_2("Stanley Liman");
    es_28_2.insert(7, es_28_1);

    // insert(size_type, const EString&, size_type, size_type)
    EString es_29_1(" H. ");
    EString es_29_2("Thomas Cormen");
    es_29_2.insert(7, es_29_1, 1, 3);

    // insert(const_iterator, value_type)
    EString es_30("Charles E Leiserson");
    es_30.insert(es_30.begin() + 9, '.');

    // insert(const_iterator, size_type, value_type)
    EString es_31("Sco Meyers");
    es_31.insert(es_31.begin() + 3, 2, 't');

    // insert(const_iterator, It, It)
    std::vector<char> v_32 = {' ', 'L', '.', ' '};
    EString es_32("Jon Bentley");
    es_32.insert(es_32.begin() + 4, v_32.begin() + 1, v_32.begin() + 4);

    // insert(const_iterator, std::initializer_list<value_type>)
    EString es_33("Charles Leiserson");
    es_33.insert(es_33.begin() + 7, {' ', 'E', '.'});

    // insert(size_type, const std::string&)
    std::string s_34("str");
    EString es_34("Bjarne Strouup");
    es_34.insert(12, s_34);

    // insert(size_type, const std::string&, size_type, size_type)
    std::string s_35(" ander ");
    EString es_35("Alex Stepanov");
    es_35.insert(4, s_35, 1, 5);

    // clear()
    EString es_36("Srinivasa Ramanujan");
    es_36.clear();

    // pop_back(), push_back(value_type)
    EString es_37("William Felle ");
    es_37.pop_back();
    es_37.push_back('r');

    // erase(const_iterator)
    EString es29("Frank Harrary");
    EString::const_iterator it3 = es29.erase(es29.begin() + 8);

    // erase(const_iterator, const_iterator)
    EString es30("Gilbert Strang");
    EString::const_iterator it4 = es30.erase(es30.begin() + 3, es30.begin() + 7);

    // replace(size_type, size_type, const EString&, size_type, size_type)
    EString es31("Ronald Graham, Joel Spencer, and Oren Patashnik");
    EString es32("Donald E. Knuth, Tracy L. Larrabee, and Paul M. Roberts");
    es31.replace(15, 13, es32, 0, 16);

    // replace(const_iterator, const_iterator, std::initializer_list<value_type>)
    EString es33("Thomas Cormen, Clifford Stein, and Ronald Rivest");
    es33.replace(es33.begin() + 15, es33.begin() + 29, {'C', 'h', 'a', 'r', 'l', 'e', 's', ' ', 'L', 'e', 'i', 's', 'e', 'r', 's', 'o', 'n'});

    // copy(value_type*, size_type, size_type)
    EString es34("Srinivasa Ramanujan");
    char dest1[10];
    size_t copied_chars = es34.copy(dest1, 9, 10);
    dest1[copied_chars] = '\0';

    // resize(size_type, char)
    EString es35("1");
    es35.resize(101, '0');

    // resize(size_type, char)
    EString es36("1");
    es36.resize(101);

    // swap(EString&)
    es36.swap(es35);

    // append(size_type, value_type)
    EString es37("Marshall Ha");
    es37.append(2, 'l');

    // append(const EString&)
    EString es38(" Jr.");
    es37.append(es38);

    // append(const EString&, size_type, size_type)
    EString es39("John Edensor Little");
    EString es40("Edward Brerewood");
    es39.append(es40, 12, 4);

    // append(const value_type*, size_type)
    EString es41("James");
    es41.append(" Mercer Ellington", 7);

    // append(const value_type*)
    EString es42("Sam");
    es42.append(" Loyd");

    // append(It, It)
    EString es43("Terence Chi-Shen");
    std::vector<char> vec3 = {' ', 'T', 'a', 'o'};
    es43.append(vec3.begin(), vec3.end());

    // append(std::initializer_list<value_type>)
    EString es44("Richard");
    es44.append({' ', 'S', 't', 'a', 'l', 'l', 'm', 'a', 'n'});

    // append(const std::string&)
    EString es45("Paul");
    std::string s6(" Erdős");
    es45.append(s6);

    // append(const std::string&, size_type, size_type)
    EString es46("Grigori Yakovlevich");
    std::string s7("Yakov Isidorovich Perelman");
    es46.append(s7, 17, 9);

    // substr(size_type, size_type)
    EString es47("Gerald L. Thompson, John G. Kemeny, and J. Laurie Snell");
    EString es48 = es47.substr(20, 14);

    // operator+(const EString&, const EString&)
    EString es49("The Art");
    EString es50(" of Computer Programming");
    EString es51(es49 + es50);

    // operator+(const EString&, const value_type*)
    EString es52("Concrete");
    const char* str1 = " Mathematics";
    EString es53(es52 + str1);

    // operator+(const EString&, value_type)
    EString es54("What is the name of this book");
    EString es55 = es54 + '?';

    // operator+(const EString&, const std::string&)
    EString es56("A Discipline");
    std::string s8 = " of Programming";
    EString es57 = es56 + s8;

    // operator+(const EString::value_type*, const EString&)
    const char* str2 = "The Science";
    EString es58(" of Programming");
    EString es59 = str2 + es58;

    // operator+(EString::value_type, const EString&)
    EString es60("tructure and Interpretation of Computer Programs");
    EString es61 = 'S' + es60;

    // operator+(const std::string&, const EString&)
    std::string s9 = "Gödel, Escher, Bach:";
    EString es62(" an Eternal Golden Braid");
    EString es63 = s9 + es62;

    // operator+(EString&&, EString&&)
    EString es64 = EString("Introduction") + EString(" to Algorithms");

    // operator+(EString&&, const EString&)
    EString es65(" Cryptography");
    EString es66 = EString("Applied") + es65;

    // operator+(EString&&, const EString::value_type*)
    const char* str3 = " of C++";
    EString es67 = EString("A Tour") + str3;

    // operator+(EString&&, EString::value_type)
    char ch1 = 'r';
    EString es68 = EString("C++ Prime") + ch1;

    // operator+(EString&&, const std::string&)
    std::string s10 = " of Mathematical Analysis";
    EString es69 = EString("Principles") + s10;

    // operator+(const EString&, EString&&)
    EString es70("Linear Algebra");
    EString es71 = es70 + EString(" and Its Applications");

    // operator+(const EString::value_type*, EString&&)
    const char* str4 = "An Introduction to Probability Theory";
    EString es72 = str4 + EString(" and Its Applications");

    // operator+(EString::value_type, EString&&)
    char ch2 = 'A';
    EString es73 = ch2 + EString("lgorithmique algébrique avec exercices corrigés");

    // operator+(const std::string&, EString&&)
    std::string s11 = "Introduction";
    EString es74 = s11 + EString(" to Automata Theory, Languages, and Computation");

    // find(const EString&, size_type pos = 0)
    EString str_1("Andrei Alexandrescu");
    EString sub_1("ndre");
    EString::size_type found_pos_1 = str_1.find(sub_1);
    EString::size_type found_pos_1_1 = str_1.find(sub_1, 7);

    // find(const value_type*, size_type, size_type)
    EString str_2("Stanley B. Lippman");
    const char* sub_2 = "anley";
    EString::size_type found_pos_2 = str_2.find(sub_2, 7, 2);

    // find(const value_type*, size_type pos = 0)
    EString str_3("William Feller");
    const char* sub_3 = "ll";
    EString::size_type found_pos_3 = str_3.find(sub_3);
    EString::size_type found_pos_3_1 = str_3.find(sub_3, 7);

    // find(const std::string&, size_type, size_type)
    EString str_4("Stanley B. Lippman");
    std::string sub_4 = "anley";
    EString::size_type found_pos_4 = str_4.find(sub_4, 7, 2);

    // find(const std::string&, size_type pos = 0)
    EString str_5("William Feller");
    std::string sub_5 = "ll";
    EString::size_type found_pos_5 = str_5.find(sub_5);
    EString::size_type found_pos_5_1 = str_3.find(sub_5, 7);

    // find(value_type, size_type pos = 0)
    EString str_6("Edsger W. Dijkstra");
    EString::size_type found_pos_6 = str_6.find('W');
    EString::size_type found_pos_6_1 = str_6.find('s', 7);

    // rfind(const EString&, size_type pos = npos)
    EString str_7("Andrei Alexandrescu");
    EString sub_7("ndre");
    EString::size_type found_pos_7 = str_7.rfind(sub_7);
    EString::size_type found_pos_7_1 = str_7.rfind(sub_7, 5);

    // rfind(const value_type*, size_type, size_type)
    EString str_8("Frank Harrary");
    const char* sub_8 = "rank";
    EString::size_type found_pos_8 = str_8.rfind(sub_8, 5, 2);

    // rfind(const value_type*, size_type pos = npos)
    EString str_9("Grigori Perelman");
    const char* sub_9 = "ri";
    EString::size_type found_pos_9 = str_9.rfind(sub_9);
    EString::size_type found_pos_9_1 = str_9.rfind(sub_9, 4);

    // rfind(const std::string&, size_type, size_type)
    EString str_10("Frank Harrary");
    std::string sub_10 = "rank";
    EString::size_type found_pos_10 = str_10.rfind(sub_10, 5, 2);

    // rfind(const std::string&, size_type pos = npos)
    EString str_11("William Feller");
    std::string sub_11 = "ll";
    EString::size_type found_pos_11 = str_11.rfind(sub_11);
    EString::size_type found_pos_11_1 = str_11.rfind(sub_11, 7);

    // rfind(value_type, size_type pos = npos)
    EString str_12("Edsger W. Dijkstra");
    EString::size_type found_pos_12 = str_12.rfind('W');
    EString::size_type found_pos_12_1 = str_12.rfind('s', 7);

    // find_first_of(const EString&, size_type pos = 0)
    EString str_13("David Gries");
    EString chars_13("hi");
    EString::size_type found_pos_13 = str_13.find_first_of(chars_13, 6);

    // find_first_of(const value_type*, size_type, size_type)
    EString str_14("Thomas H. Cormen");
    const char* chars_14 = "hello";
    EString::size_type found_pos_14 = str_14.find_first_of(chars_14, 7, 2);

    // find_first_of(const value_type*, size_type pos = 0)
    EString str_15("A. V. Aho & J. E. Hopcroft");
    const char* chars_15 = "!@#$%^&*()_+";
    EString::size_type found_pos_15 = str_15.find_first_of(chars_15);

    // find_first_of(const std::string&, size_type, size_type)
    EString str_16("Thomas H. Cormen");
    std::string chars_16 = "hello";
    EString::size_type found_pos_16 = str_16.find_first_of(chars_16, 7, 2);

    // find_first_of(const std::string&, size_type pos = 0)
    EString str_17("A. V. Aho & J. E. Hopcroft");
    std::string chars_17 = "!@#$%^&*()_+";
    EString::size_type found_pos_17 = str_17.find_first_of(chars_17);

    // find_first_of(value_type, size_type pos = 0)
    EString str_18("Edsger W. Dijkstra");
    EString::size_type found_pos_18 = str_18.find_first_of('W');
    EString::size_type found_pos_18_1 = str_18.find_first_of('s', 7);

    // find_first_not_of(const EString&, size_type pos = 0)
    EString str_19("David Gries");
    EString chars_19("DG");
    EString::size_type found_pos_19 = str_19.find_first_not_of(chars_19);

    // find_first_not_of(const value_type*, size_type, size_type)
    EString str_20("Andrei Alexandrescu");
    const char* chars_20 = "lexand";
    EString::size_type found_pos_20 = str_20.find_first_not_of(chars_20, 8, 5);

    // find_first_not_of(const value_type*, size_type pos = 0)
    EString str_21("A. V. Aho & J. E. Hopcroft");
    const char* chars_21 = " AV.";
    EString::size_type found_pos_21 = str_21.find_first_not_of(chars_21);

    // find_first_not_of(const std::string&, size_type, size_type)
    EString str_22("Andrei Alexandrescu");
    std::string chars_22 = "lexand";
    EString::size_type found_pos_22 = str_22.find_first_not_of(chars_22, 8, 5);

    // find_first_not_of(const std::string&, size_type pos = 0)
    EString str_23("A. V. Aho & J. E. Hopcroft");
    std::string chars_23 = " AV.";
    EString::size_type found_pos_23 = str_23.find_first_not_of(chars_23);

    // find_first_not_of(value_type, size_type pos = 0)
    EString str_24("Frank Harrary");
    EString::size_type found_pos_24 = str_24.find_first_not_of('r', 8);

    // find_last_of(const EString&, size_type pos = npos)
    EString str_25("Bjarne Stroustrup");
    EString chars_25("qrstv");
    EString::size_type found_pos_25 = str_25.find_last_of(chars_25, 11);

    // find_last_of(const value_type*, size_type, size_type)
    EString str_26("Donald Knuth");
    const char* chars_26 = "hjklmnp";
    EString::size_type found_pos_26 = str_26.find_last_of(chars_26, 7, 5);

    // find_last_of(const value_type*, size_type pos = npos)
    EString str_27("Donald Knuth");
    const char* chars_27 = "jklmnp";
    EString::size_type found_pos_27 = str_27.find_last_of(chars_27);

    // find_last_of(const std::string&, size_type, size_type)
    EString str_28("Donald Knuth");
    std::string chars_28 = "hjklmnp";
    EString::size_type found_pos_28 = str_28.find_last_of(chars_28, 7, 5);

    // find_last_of(const std::string&, size_type pos = npos)
    EString str_29("Donald Knuth");
    std::string chars_29 = "jklmnp";
    EString::size_type found_pos_29 = str_29.find_last_of(chars_29);

    // find_last_of(value_type, size_type pos = npos)
    EString str_30("Edsger W. Dijkstra");
    EString::size_type found_pos_30 = str_30.find_last_of('r');
    EString::size_type found_pos_30_1 = str_30.find_last_of('r', 7);

    // find_last_not_of(const EString&, size_type pos = npos)
    EString str_31("Srinivasa Ramanujan");
    EString chars_31("ajnu");
    EString::size_type found_pos_31 = str_31.find_last_not_of(chars_31);
    EString::size_type found_pos_31_1 = str_31.find_last_not_of(chars_31, 8);

    // find_last_not_of(const value_type*, size_type, size_type)
    EString str_32("Scott Meyers");
    const char* chars_32 = "rst";
    EString::size_type found_pos_32 = str_32.find_last_not_of(chars_32, 11, 2);

    // find_last_not_of(const value_type*, size_type pos = npos)
    EString str_33("Jon Bentley");
    const char* chars_33 = "aeiouy";
    EString::size_type found_pos_33 = str_33.find_last_not_of(chars_33);

    // find_last_not_of(const std::string&, size_type, size_type)
    EString str_34("Scott Meyers");
    std::string chars_34 = "rst";
    EString::size_type found_pos_34 = str_34.find_last_not_of(chars_34, 11, 2);

    // find_last_not_of(const std::string&, size_type pos = npos)
    EString str_35("Jon Bentley");
    std::string chars_35 = "aeiouy";
    EString::size_type found_pos_35 = str_35.find_last_not_of(chars_35);

    // find_last_not_of(value_type, size_type pos = npos)
    EString str_36("Charles Wetherell");
    EString::size_type found_pos_36 = str_36.find_last_not_of('l');


    return 0;
}




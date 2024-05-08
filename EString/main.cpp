#include <iostream>
#include <vector>
#include "EString.h"


EString demo(EString str) {
    return str;
}

int main() {
    // EString()
    EString es1;

    // EString(const value_type*)
    EString es2("Edsger W. Dijkstra");

    // EString(const value_type*)
    EString es3 = "David Gries";

    // EString(const value_type*, size_type)
    EString es4("Thomas H. Cormen is an emeritus professor", 16);

    // EString(size_type, value_type)
    EString es5(2, 'V');

    // EString(std::initializer_list<value_type>)
    EString es6({'D', 'o', 'n', 'a', 'l', 'd', ' ', 'K', 'n', 'u', 't', 'h'});

    // EString(It, It)
    char arr1[] = {'U', 'n', 'c', 'l', 'e', ' ', 'B', 'o', 'b'};
    EString es7(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));

    // EString(const std::string&)
    std::string s1("Bjarne Stroustrup");
    EString es8(s1);

    // EString(const EString&)
    EString es9(es2);

    // operator=(const EString&)
    EString es10 = es3;

    // EString(EString&&)
    EString temp1("Alexander Stepanov");
    EString es11 = demo(std::move(temp1));

    // operator=(EString&&)
    EString temp2("Scott Meyers");
    EString es12;
    es12 = std::move(temp2);

    // operator=(const std::string&)
    std::string s2("Andrei Alexandrescu");
    EString es13 = s2;

    // begin(), end(), rbegin(), rend()
    EString es14("LIVE");
    for (EString::iterator it = es14.begin(); it != es14.end(); ++it) {
        // std::cout << *it;
    }
    // std::cout << std::endl;
    for (EString::reverse_iterator it = es14.rbegin(); it != es14.rend(); ++it) {
        // std::cout << *it;
    }
    // std::cout << std::endl;

    // at(size_type)
    es5.at(1) = 'i';
    // std::cout << es5 << std::endl;

    // operator[](size_type)
    es5[0] = 'p';
    // std::cout << es5 << std::endl;

    // front(), back()
    // std::cout << es5.back() << es5.front() << std::endl;

    // assign(const value_type*)
    es9.assign("Jon Bentley");

    // assign(const value_type*, size_type)
    es14.assign("Robert Sedgewick is an American computer scientist", 16);

    // assign(size_type, value_type)
    es5.assign(3, 'D');

    // assign(It, It)
    std::vector<char> vec1 = {'R', 'o', 'b', 'e', 'r', 't', ' ', 'C', 'e', 'c', 'i', 'l', ' ', 'M', 'a', 'r', 't', 'i', 'n'};
    es7.assign(vec1.begin(), vec1.end());

    // assign(const EString&)
    es1.assign(es14);

    // assign(const EString&, size_type, size_type)
    EString es15 = "Etudes for Programmers by Charles Wetherell (Author)";
    es3.assign(es15, 26, 17);

    // assign(EString&&)
    EString temp3("Stanley B. Lippman");
    es15.assign(std::move(temp3));

    // assign(std::initializer_list<value_type>)
    es5.assign({'B', 'r', 'u', 'c', 'e', ' ', 'S', 'c', 'h', 'n', 'e', 'i', 'e', 'r'});

    // assign(const std::string&)
    es8.assign(s2);

    // assign(const std::string&, size_type, size_type)
    std::string s3("Professor Walter Rudin was an Austrian-American mathematician");
    es13.assign(s3, 10, 12);

    // insert(size_type, size_type, value_type)
    EString es16("Raymond Merri Smuyan");
    es16.insert(13, 2, 'l');
    es16.insert(19, 2, 'l');

    // insert(size_type, const value_type*)
    es6.insert(6, " Ervin");

    // EString& insert(size_type, const value_type*, size_type)
    EString es17("Demidovich");
    es17.insert(0, "Boris Spassky", 6);

    // insert(size_type, const const EString&)
    EString es18("Douglas Hofstadter");
    EString es19(" Richard");
    es18.insert(7, es19);

    // insert(size_type, const EString&, size_type, size_type)
    EString es20("Christopher Date");
    EString es21("A. V. Aho & J. E. Hopcroft");
    es20.insert(11, es21, 11, 3);

    // insert(const_iterator, value_type)
    EString es22("Charles E Leiserson");
    EString::const_iterator it1 = es22.begin() + 9;
    EString::iterator insertedIt1 = es22.insert(it1, '.');

    // insert(const_iterator, size_type, value_type)
    EString es23("Cliord Stein");
    EString::const_iterator it2 = es23.begin() + 3;
    EString::iterator insertedIt2 = es23.insert(it2, 2, 'f');

    // insert(const_iterator, It, It)
    EString es24("Gerald Sussman");
    std::vector<char> vec2 = {'V', 'e', 'e', '-', 'J', 'a', 'y', ' ', 'R', 'e', 'c', 'o', 'r', 'd', 's'};
    es24.insert(es24.begin() + 7, vec2.begin() + 4, vec2.begin() + 8);

    // insert(const_iterator, std::initializer_list<value_type>)
    EString es25("Kenneth Thompson");
    es25.insert(es25.begin() + 7, {' ', 'L', 'a', 'n', 'e'});

    // insert(size_type, const std::string&)
    EString es26("Dennis Ritchie");
    std::string s4(" MacAlistair");
    es26.insert(6, s4);

    // insert(size_type, const std::string&, size_type, size_type)
    EString es27("Linus Torvalds");
    std::string s5("Saint Benedict");
    es27.insert(5, s5, 5, 9);

    // clear()
    es1.clear();

    // pop_back(), push_back(value_type)
    EString es28("William Felle ");
    es28.pop_back();
    es28.push_back('r');

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




    return 0;
}




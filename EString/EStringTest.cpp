#include "EStringTest.h"
#include "EString.h"
#include <vector>


void EStringTest() {
        // EString(const value_type*)
        EString es_1("Edsger Dijkstra");

        // EString(const value_type*)
        EString es_2 = "David Gries";

        // EString(const value_type*, size_type)
        EString es_3("Thomas Cormen ", 13);

        // EString(std::initializer_list<value_type>)
        EString es_4({'D', 'o', 'n', 'a', 'l', 'd', ' ', 'K', 'n', 'u', 't', 'h'});

        // EString(It, It), begin(), end()
        char arr_5[] = "Donald Knuth";
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
        EString es_38("Frank Harrary");
        es_38.erase(es_38.begin() + 8);

        // erase(const_iterator, const_iterator)
        EString es_39("Gilbert Strang");
        es_39.erase(es_39.begin() + 3, es_39.begin() + 7);

        // replace(size_type, size_type, const EString&, size_type, size_type)
        EString es_40_1("Donald Knuth, Daniel Greene");
        EString es_40_2("Ronald Graham, Marshall Hall, Oren Patashnik");
        es_40_2.replace(15, 13, es_40_1, 0, 12);

        // replace(const_iterator, const_iterator, std::initializer_list<value_type>)
        EString es_41("Thomas Cormen, Clifford Stein, Ronald Rivest");
        es_41.replace(es_41.begin() + 15, es_41.begin() + 29, {'C', 'h', 'a', 'r', 'l', 'e', 's', ' ', 'L', 'e', 'i', 's', 'e', 'r', 's', 'o', 'n'});

        // copy(value_type*, size_type, size_type)
        EString es_42("Ronald Graham, Donald Knuth, Oren Patashnik");
        char dest_42[12];
        dest_42[es_42.copy(dest_42, 12, 15)] = '\0';

        // resize(size_type, char), resize(size_type)
        EString es_43("Marshall Ha");
        es_43.resize(14, 'l');
        es_43.resize(13);

        // swap(EString&)
        EString es_44_1("Srinivasa Ramanujan");
        EString es_44_2("Ronald Graham");
        es_44_2.swap(es_44_1);

        // append(size_type, value_type), append(const EString&)
        EString es_45_1(" Jr.");
        EString es_45_2("Marshall Ha");
        es_45_2.append(2, 'l');
        es_45_2.append(es_45_1);

        // append(const EString&, size_type, size_type)
        EString es_46_1(" wood");
        EString es_46_2("John Little");
        es_46_2.append(es_46_1, 1, 4);

        // append(const value_type*, size_type), append(const value_type*)
        EString es_47("G.");
        es_47.append(" H. ", 3);
        es_47.append(" Hardy");

        // append(It, It), append(std::initializer_list<value_type>) Chi-Shen
        std::vector<char> v_48 = {' ', 'C', 'h', 'i', '-', 'S', 'h', 'e', 'n'};
        EString es_48("Terence");
        es_48.append(v_48.begin(), v_48.end());
        es_48.append({' ', 'T', 'a', 'o'});

        // append(const std::string&), append(const std::string&, size_type, size_type)
        std::string s_49_1("Yakovlevich ");
        std::string s_49_2(" Perelman ");
        EString es_49("Grigori ");
        es_49.append(s_49_1);
        es_49.append(s_49_2, 1, 8);

        // substr(size_type, size_type)
        EString es_50_1("Thomas Cormen, Charles Leiserson, Ronald Rivest");
        EString es_50_2 = es_50_1.substr(15, 17);

        // operator+(const EString&, const EString&)
        EString es_51_1("Paul");
        EString es_51_2(" Erdős");
        EString es_51_3(es_51_1 + es_51_2);

        // operator+(const EString&, const value_type*)
        EString es_52_1("Terence");
        EString es_52_2(es_52_1 + " Tao");

        // operator+(const EString&, value_type)
        EString es_53_1("Dennis Ritchi");
        EString es_53_2 = es_53_1 + 'e';

        // operator+(const EString&, const std::string&)
        std::string s_54 = " Torvalds";
        EString es_54_1("Linus");
        EString es_54_2(es_54_1 + s_54);

        // operator+(const EString::value_type*, const EString&)
        EString es_55_1(" Ritchie");
        EString es_55_2 = "Dennis" + es_55_1;

        // operator+(EString::value_type, const EString&)
        EString es_56_1("rinivasa Ramanujan");
        EString es_56_2 = 'S' + es_56_1;

        // operator+(const std::string&, const EString&)
        std::string s_57 = "Gilbert";
        EString es_57_1(" Strang");
        EString es_57_2 = s_57 + es_57_1;

        // operator+(EString&&, EString&&)
        EString es_58 = EString("Linus") + EString(" Torvalds");

        // operator+(EString&&, const EString&)
        EString es_59_1(" Hardy");
        EString es_59_2 = EString("G. H.") + es_59_1;

        // operator+(EString&&, const EString::value_type*)
        EString es_60 = EString("John Little") + "wood";

        // operator+(EString&&, EString::value_type)
        EString es_61 = EString("Stanley Lippma") + 'n';

        // operator+(EString&&, const std::string&)
        std::string s_62 = " Erdős";
        EString es_62 = EString("Paul") + s_62;

        // operator+(const EString&, EString&&)
        EString es_63_1("Camille");
        EString es_63_2 = es_63_1 + EString(" Jordan");

        // operator+(const EString::value_type*, EString&&)
        EString es_64 = "Ronald " + EString("Rivest");

        // operator+(EString::value_type, EString&&)
        EString es_65 = 'J' + EString("on Bentley");

        // operator+(const std::string&, EString&&)
        std::string s_66 = "Robert";
        EString es_66 = s_66 + EString(" Sedgewick");

        // find(const EString&, size_type pos = 0)
        EString es_67_1("Andrei Alexandrescu");
        EString es_67_2("ndre");
        EString::size_type p_67_1 = es_67_1.find(es_67_2);
        EString::size_type p_67_2 = es_67_1.find(es_67_2, 7);

        // find(const value_type*, size_type, size_type)
        EString es_68("Stanley Lippman");
        const char* c_68 = "anley";
        EString::size_type p_68 = es_68.find(c_68, 7, 2);

        // find(const value_type*, size_type pos = 0)
        EString es_69("William Feller");
        const char* c_69 = "ll";
        EString::size_type p_69_1 = es_69.find(c_69);
        EString::size_type p_69_2 = es_69.find(c_69, 7);

        // find(const std::string&, size_type, size_type)
        EString es_70("Stanley B. Lippman");
        std::string s_70 = "anley";
        EString::size_type p_70 = es_70.find(s_70, 7, 2);

        // find(const std::string&, size_type pos = 0)
        EString es_71("William Feller");
        std::string s_71 = "ll";
        EString::size_type p_71_1 = es_71.find(s_71);
        EString::size_type p_71_2 = es_71.find(s_71, 7);

        // find(value_type, size_type pos = 0)
        EString es_72("Edsger W. Dijkstra");
        EString::size_type p_72_1 = es_72.find('W');
        EString::size_type p_72_2 = es_72.find('s', 7);

        // rfind(const EString&, size_type pos = npos)
        EString es_73("Andrei Alexandrescu");
        EString s_73("ndre");
        EString::size_type p_73_1 = es_73.rfind(s_73);
        EString::size_type p_73_2 = es_73.rfind(s_73, 5);

        // rfind(const value_type*, size_type, size_type)
        EString es_74("Frank Harrary");
        const char* c_74 = "rank";
        EString::size_type p_74 = es_74.rfind(c_74, 5, 2);

        // rfind(const value_type*, size_type pos = npos)
        EString es_75("Grigori Perelman");
        const char* c_75 = "ri";
        EString::size_type p_75_1 = es_75.rfind(c_75);
        EString::size_type p_75_2 = es_75.rfind(c_75, 4);

        // rfind(const std::string&, size_type, size_type)
        EString es_76("Frank Harrary");
        std::string s_76 = "rank";
        EString::size_type p_76 = es_76.rfind(s_76, 5, 2);

        // rfind(const std::string&, size_type pos = npos)
        EString es_77("William Feller");
        std::string s_77 = "ll";
        EString::size_type p_77_1 = es_77.rfind(s_77);
        EString::size_type p_77_2 = es_77.rfind(s_77, 7);

        // rfind(value_type, size_type pos = npos)
        EString es_78("Edsger W. Dijkstra");
        EString::size_type p_78_1 = es_78.rfind('W');
        EString::size_type p_78_2 = es_78.rfind('s', 7);

        // find_first_of(const EString&, size_type pos = 0)
        EString es_79_1("David Gries");
        EString es_79_2("hi");
        EString::size_type p_79 = es_79_1.find_first_of(es_79_2, 6);

        // find_first_of(const value_type*, size_type, size_type)
        EString es_80("Thomas Cormen");
        const char* c_80 = "hello";
        EString::size_type p_80 = es_80.find_first_of(c_80, 7, 2);

        // find_first_of(const value_type*, size_type pos = 0)
        EString es_81("A. Aho & J. Hopcroft");
        const char* c_81 = "@#$%^&*()";
        EString::size_type p_81 = es_81.find_first_of(c_81);

        // find_first_of(const std::string&, size_type, size_type)
        EString es_82("Thomas Cormen");
        std::string s_82 = "hello";
        EString::size_type p_82 = es_82.find_first_of(s_82, 7, 2);

        // find_first_of(const std::string&, size_type pos = 0)
        EString es_83("A. Aho & J. Hopcroft");
        std::string c_83 = "@#$%^&*()";
        EString::size_type p_83 = es_83.find_first_of(c_83);

        // find_first_of(value_type, size_type pos = 0)
        EString es_84("Edsger W. Dijkstra");
        EString::size_type p_84_1 = es_84.find_first_of('W');
        EString::size_type p_84_2 = es_84.find_first_of('s', 7);

        // find_first_not_of(const EString&, size_type pos = 0)
        EString es_85_1("David Gries");
        EString es_85_2("DG");
        EString::size_type p_85 = es_85_1.find_first_not_of(es_85_2);

        // find_first_not_of(const value_type*, size_type, size_type)
        EString es_86("Andrei Alexandrescu");
        const char* c_86 = "lexand";
        EString::size_type p_86 = es_86.find_first_not_of(c_86, 8, 5);

        // find_first_not_of(const value_type*, size_type pos = 0)
        EString es_87("A. Aho & J. Hopcroft");
        const char* c_87 = " A.";
        EString::size_type p_87 = es_87.find_first_not_of(c_87);

        // find_first_not_of(const std::string&, size_type, size_type)
        EString es_88("Andrei Alexandrescu");
        std::string s_88 = "lexand";
        EString::size_type p_88 = es_88.find_first_not_of(s_88, 8, 5);

        // find_first_not_of(const std::string&, size_type pos = 0)
        EString es_89("A. Aho & J. Hopcroft");
        std::string s_89 = " A.";
        EString::size_type p_89 = es_89.find_first_not_of(s_89);

        // find_first_not_of(value_type, size_type pos = 0)
        EString es_90("Frank Harrary");
        EString::size_type p_90 = es_90.find_first_not_of('r', 8);

        // find_last_of(const EString&, size_type pos = npos)
        EString es_91_1("Bjarne Stroustrup");
        EString es_91_2("qrstv");
        EString::size_type p_91 = es_91_1.find_last_of(es_91_2, 11);

        // find_last_of(const value_type*, size_type, size_type)
        EString es_92("Donald Knuth");
        const char* c_92 = "hjklmnp";
        EString::size_type p_92 = es_92.find_last_of(c_92, 7, 5);

        // find_last_of(const value_type*, size_type pos = npos)
        EString es_93("Donald Knuth");
        const char* c_93 = "jklmnp";
        EString::size_type p_93 = es_93.find_last_of(c_93);

        // find_last_of(const std::string&, size_type, size_type)
        EString es_94("Donald Knuth");
        std::string c_94 = "hjklmnp";
        EString::size_type p_94 = es_94.find_last_of(c_94, 7, 5);

        // find_last_of(const std::string&, size_type pos = npos)
        EString es_95("Donald Knuth");
        std::string s_95 = "jklmnp";
        EString::size_type p_95 = es_95.find_last_of(s_95);

        // find_last_of(value_type, size_type pos = npos)
        EString es_96("Edsger W. Dijkstra");
        EString::size_type p_96_1 = es_96.find_last_of('r');
        EString::size_type p_96_2 = es_96.find_last_of('r', 7);

        // find_last_not_of(const EString&, size_type pos = npos)
        EString es_97_1("Srinivasa Ramanujan");
        EString es_97_2("ajnu");
        EString::size_type p_97_1 = es_97_1.find_last_not_of(es_97_2);
        EString::size_type p_97_2 = es_97_1.find_last_not_of(es_97_2, 8);

        // find_last_not_of(const value_type*, size_type, size_type)
        EString es_98("Scott Meyers");
        const char* c_98 = "rst";
        EString::size_type p_98 = es_98.find_last_not_of(c_98, 11, 2);

        // find_last_not_of(const value_type*, size_type pos = npos)
        EString es_99("Jon Bentley");
        const char* c_99 = "aeiouy";
        EString::size_type p_99 = es_99.find_last_not_of(c_99);

        // find_last_not_of(const std::string&, size_type, size_type)
        EString es_100("Scott Meyers");
        std::string s_100 = "rst";
        EString::size_type p_100 = es_100.find_last_not_of(s_100, 11, 2);

        // find_last_not_of(const std::string&, size_type pos = npos)
        EString es_101("Jon Bentley");
        std::string s_101 = "aeiouy";
        EString::size_type p_101 = es_101.find_last_not_of(s_101);

        // find_last_not_of(value_type, size_type pos = npos)
        EString es_102("Charles Wetherell");
        EString::size_type p_102 = es_102.find_last_not_of('l');

        // operator==(const EString&, const EString&)
        EString es_103_1("Linus Torvalds");
        EString es_103_2("Linus Torvalds");
        bool r_103 = es_103_1 == es_103_2;

        // operator==(const EString&, const EString::value_type*)
        EString es_104("Linus Torvalds");
        bool r_104 = es_104 == "Linus Torvalds";

        // operator==(const EString&, const std::string&)
        EString es_105("Linus Torvalds");
        std::string s_105("Linus Torvalds");
        bool r_105 = es_105 == s_105;

        // operator==(const EString::value_type*, const EString&)
        EString es_106("Linus Torvalds");
        bool r_106 = "Linus Torvalds" == es_106;

        // operator==(const std::string&, const EString&)
        EString es_107("Linus Torvalds");
        std::string s_107("Linus Torvalds");
        bool r_107 = s_107 == es_107;

        // operator<(const EString&, const EString&)
        EString es_108_1("Linus Torvalds");
        EString es_108_2("Dennis Ritchie");
        bool r_108 = es_108_1 < es_108_2;

        // operator<(const EString&, const EString::value_type*)
        EString es_109("Linus Torvalds");
        bool r_109 = es_109 < "Dennis Ritchie";

        // operator<(const EString&, const std::string&)
        EString es_110("Linus Torvalds");
        std::string s_110("Dennis Ritchie");
        bool r_110 = es_110 < s_110;

        // operator<(const EString::value_type*, const EString&)
        EString es_111("Dennis Ritchie");
        bool r_111 = "Linus Torvalds" < es_111;

        // operator<(const std::string&, const EString&)
        EString es_112("Dennis Ritchie");
        std::string s_112("Linus Torvalds");
        bool r_112 = s_112 < es_112;
}
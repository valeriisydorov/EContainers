#include <iostream>
#include <vector>
#include "EString.h"


EString demo(EString str) {
    return str;
}

int main() {
    // Example usage of the EString() constructor
    EString es1;

    // Example usage of the EString(const value_type*) constructor (a string literal)
    EString es2("Edsger W. Dijkstra");

    // Example usage of the EString(const value_type*) constructor (a string literal using an assignment operator)
    EString es3 = "David Gries";

    // Example usage of the EString(const value_type*, size_type) constructor (a part of a string literal)
    EString es4("Thomas H. Cormen is an emeritus professor", 16);

    // Example usage of the EString(size_type, value_type) constructor (repeating characters)
    EString es5(2, 'V');

    // Example usage of the EString(std::initializer_list<value_type>) constructor (a std::initializer list)
    EString es6({'D', 'o', 'n', 'a', 'l', 'd', ' ', 'K', 'n', 'u', 't', 'h'});

    // Example usage of the EString(It, It) constructor (two iterators)
    char arr1[] = {'U', 'n', 'c', 'l', 'e', ' ', 'B', 'o', 'b'};
    EString es7(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));

    // Example usage of the EString(const std::string&) constructor (an std::string)
    std::string s1("Bjarne Stroustrup");
    EString es8(s1);

    // Example usage of the EString(const EString&) copy constructor (an EString)
    EString es9(es2);

    // Example usage of the operator=(const EString&) assignment operator (an EString)
    EString es10 = es3;

    // Example usage of the EString(EString&&) move constructor (an EString)
    EString temp1("Alexander Stepanov");
    EString es11 = demo(std::move(temp1));

    // Example usage of the operator=(EString&&) move assignment operator (an EString)
    EString temp2("Scott Meyers");
    EString es12;
    es12 = std::move(temp2);

    // Example usage of the operator=(const std::string&) assignment operator (a std::string)
    std::string s2("Andrei Alexandrescu");
    EString es13 = s2;

    // Example usage of the begin(), the end() forward iterators and the rbegin(), the rend() reverse iterators
    EString es14("LIVE");
    for (EString::iterator it = es14.begin(); it != es14.end(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    for (EString::reverse_iterator it = es14.rbegin(); it != es14.rend(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;

    // Example usage of the at(size_type) function
    es5.at(1) = 'i';
    std::cout << es5 << std::endl;

    // Example usage of the operator[](size_type) indexing operator
    es5[0] = 'p';
    std::cout << es5 << std::endl;

    // Example usage of the front() and the back() functions
    std::cout << es5.back() << es5.front() << std::endl;

    // Example usage of the assign(const value_type*) function (a string literal)
    es9.assign("Jon Bentley");

    // Example usage of the assign(const value_type*, size_type) function (a part of a string literal)
    es14.assign("Robert Sedgewick is an American computer scientist", 16);

    // Example usage of the assign(size_type, value_type) function (repeating characters)
    es5.assign(3, 'D');

    // Example usage of the assign(It, It) function (two iterators)
    std::vector<char> vec1 = {'R', 'o', 'b', 'e', 'r', 't', ' ', 'C', 'e', 'c', 'i', 'l', ' ', 'M', 'a', 'r', 't', 'i', 'n'};
    es7.assign(vec1.begin(), vec1.end());

    // Example usage of the assign(const EString&) function (an EString)
    es1.assign(es14);

    // Example usage of the assign(const EString&, size_type, size_type) function (a part of an EString)
    EString es15 = "Etudes for Programmers by Charles Wetherell (Author)";
    es3.assign(es15, 26, 17);

    // Example usage of the assign(EString&&) function (an EString)
    EString temp3("Stanley B. Lippman");
    es15.assign(std::move(temp3));

    // Example usage of the assign(std::initializer_list<value_type>) function (a std::initializer list)
    es5.assign({'B', 'r', 'u', 'c', 'e', ' ', 'S', 'c', 'h', 'n', 'e', 'i', 'e', 'r'});

    // Example usage of the assign(const std::string&) function (a std::string)
    es8.assign(s2);

    // Example usage of the assign(const std::string&, size_type, size_type) function (a part of a std::string)
    std::string s3("Professor Walter Rudin was an Austrian-American mathematician");
    es13.assign(s3, 10, 12);


    return 0;
}
 
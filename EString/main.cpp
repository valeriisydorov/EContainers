#include <iostream>
#include "EString.h"


EString demo(EString str) {
    return str;
}

int main() {
    // Creating empty EString
    EString es1;

    // Creating EString using a string literal
    EString es2("Edsger W. Dijkstra");

    // Creating EString from a string literal using assignment operator
    EString es3 = "David Gries";

    // Creating subEString using a string literal
    EString es4("Thomas H. Cormen, Emeritus Professor", 16);

    // Creating EString from repeating characters
    EString es5(2, 'V');

    // Creating EString from an initializer list
    EString es6({'D', 'o', 'n', 'a', 'l', 'd', ' ', 'K', 'n', 'u', 't', 'h'});

    // Creating EString using two iterators
    char arr1[] = {'U', 'n', 'c', 'l', 'e', ' ', 'B', 'o', 'b'};
    EString es7(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));

    // Creating EString from std::string
    std::string s1("Bjarne Stroustrup");
    EString es8(s1);

    // Creating EString with copy constructor
    EString es9(es2);

    // Creating EString with assignment operator
    EString es10 = es3;

    // Creating EString with move constructor
    EString temp1("Alexander Stepanov");
    EString es11 = demo(std::move(temp1));

    // Creating EString with move assignment operator
    EString temp2("Scott Meyers");
    EString es12;
    es12 = std::move(temp2);

    // Creating EString with assignment operator from std::string
    std::string s2("Andrei Alexandrescu");
    EString es13 = s2;

    // Forward and reverse iterators usage
    EString es14("LIVE");
    for (EString::iterator it = es14.begin(); it != es14.end(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
    for (EString::reverse_iterator it = es14.rbegin(); it != es14.rend(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;

    // Example usage of the at function
    es5.at(1) = 'i';
    std::cout << es5 << std::endl;

    // Example usage of the indexing operator
    es5[0] = 'p';
    std::cout << es5 << std::endl;

    // Example usage of the front and the back functions
    std::cout << es5.back() << es5.front() << std::endl;


    return 0;
}
 
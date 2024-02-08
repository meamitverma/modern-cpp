#include<iostream>

// string_view -> use it to display data, it is very lighter than std::string
// string_view can be used in VIEW as VIEW does not have to modify anything.

// regular way
void printSubString(std::string &str) {
    str += "Changed";
    std::cout << "Sub string:"  << str << std::endl;
}

// string view -> only to reproduce data, not mutable
void printSubString(std::string_view &str) {
    //str += "Changed"; // cannot modify as string_view is constant
    std::cout << "Sub string:"  << str << std::endl;
}

int main() {

    std::cout << "string_view\n";
    std::string str  = "Hello world";
    str[7] = '7'; // string is mutable
    std::cout << str << std::endl;

    // Phase II
    const char *cStr = "Hello world";
    std::string_view view (cStr, 5); // view first 5 characters
    // view[0] = 'X'; // string_view is constant works as a reference
    std::cout << "std::string_view: " << view << std::endl;

    // Phase III
    std::string originalString = "Hello World";
    std::string_view subStringView(originalString.c_str() + 7, 5); // show the data from 7th position to 5 character
    printSubString(subStringView);
    std::cout << "Original String " << originalString << std::endl;

    return 0;
}
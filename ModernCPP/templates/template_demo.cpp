#include<iostream>

template<bool UseFlag>
auto getValue() {
    if constexpr(UseFlag) {
        return 3.13;
    }
    else {
        return 12;
    }
}

int main() {
    std::cout << "Hello, constexpr! \n";
    int val = getValue<false>();
    std::cout << "int val! " << val << std::endl;
    double doubleVal = getValue<true>();
    std::cout << "double val! " << doubleVal << std::endl;

    return 0;
}
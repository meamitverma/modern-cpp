#include<iostream>
#include<variant>
#include<vector>

using var_t = std::variant<int, std::string>;

struct PrintInt {
    void operator()( int i ) {
        std::cout << i << std::endl;
    }
};

struct PrintString {
    void operator() (std::string str) {
        std::cout << str << std::endl;
    }
};  

struct Print : PrintInt, PrintString {
    using PrintInt::operator();
    using PrintString::operator();
};


int main() {
    std::cout << "Lambda Overload !\n" << std::endl;
    std::vector<var_t> vars = { 1, 2, "Hello WOrld", "Bangalore", 4, 5, 6};
    
    // Print p;
    for (auto &v : vars) {
        std::visit(Print{}, v); // aggregate
    }

    return 0;
}
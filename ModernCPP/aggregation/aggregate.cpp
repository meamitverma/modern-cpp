#include<iostream>
#include<variant>
#include<vector>

using var_t = std::variant<int, std::string>;

struct Print {
    void operator()( int i ) {
        std::cout << i << std::endl;
    }

    void operator()( std::string str ) {
        std::cout << str << std::endl;
    }
};


int main() {
    std::cout << "Lamvda Overload !\n" << std::endl;
    std::vector<var_t> vars = { 1, 2, "Hello WOrld", "Bangalore", 4, 5, 6};
    
    // Print p;
    for (auto &v : vars) {
        std::visit(Print{}, v); // aggregate
    }

    return 0;
}
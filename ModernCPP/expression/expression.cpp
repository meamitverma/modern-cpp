#include<iostream>

// Phase2: full expression
template<typename... T>
auto AddRecur(T ...t) {
    return (t +...);
}

constexpr  auto add() {std::cout << "Adding" << std::endl;}
constexpr auto sub() {std::cout << "Subracting" << std::endl;}
constexpr auto mul() {std::cout << "Multiplication" << std::endl;}
constexpr auto divs() {std::cout << "Division" << std::endl;}

template<typename Func>
void call(Func f) {
    f();
}

template<typename Func, typename... Funcs>
void call(Func f, Funcs... fs) {
   f();
   call(fs...);
}

int main(int argc, const char *argv[]) {

    std::cout << "Sum of full expression: " << AddRecur(1,2,3,4,5,6,"a",7,8,9,10) << std::endl;
    // call(add, 10, 20, sub, 100, 2, mul, 12, 45, fiv, 120,2);

    call(add, sub, mul, divs);

    return 0;
}
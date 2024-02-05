#include<iostream>

// constant function
constexpr auto add(const int a, const int b) -> int {
    return a + b;
}

// declare a function pointer
// (*)();
// Place holder or Callback.
int (*MyFnPtr)(int x, int y) = add;

// passing function reference as argument
// functional composition
// standard way of declaring a function
constexpr auto resultOfCalculation(int (*OP)(int, int), int x, int y) -> decltype((*OP)(x, y)) {
    return  (*OP)(x, y);
}

template<typename FN, typename T1, typename T2>
constexpr auto resultOfCalculation(
    const FN& OP,
    const T1& x,
    const T2 y
) -> decltype((*OP)(x, y)) {
    return OP(x, y);
}

// compose(add, mul, sub, div, 12, 32);

int main() {

    // outdated way of calling
    std::cout << "Sum of funptr = " << MyFnPtr(12,34) << std::endl;
    
    int res = resultOfCalculation(add, 2, 5);
    std::cout << res << std::endl;

    int res2= resultOfCalculation(add, 300, 300);
    std::cout << res2 << std::endl;
    
    return 0;
}
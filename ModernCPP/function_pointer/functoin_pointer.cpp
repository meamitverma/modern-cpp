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
int resultOfCalculation(int (*OP)(int, int), int x, int y) {
    return  (*OP)(x, y);
}

int main() {

    // outdated way of calling
    std::cout << "Sum of funptr = " << MyFnPtr(12,34) << std::endl;
    
    int res = resultOfCalculation(add, 2, 5);
    std::cout << res << std::endl;
    
    return 0;
}
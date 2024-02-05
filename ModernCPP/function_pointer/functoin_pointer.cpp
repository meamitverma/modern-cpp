#include<iostream>

// constant function
constexpr auto add(const int a, const int b) -> int {
    return a + b;
}

// declare a function pointer
// (*)();
// Place holder or Callback.
int (*MyFnPtr)(int x, int y) = add;


int main() {

    std::cout << "Sum of funptr = " << MyFnPtr(12,34) << std::endl;
    
    return 0;
}
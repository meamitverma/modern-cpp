#include<iostream>

const double PI1 = 3.141592653589793;
constexpr double PI2 = 3.141592653589793;
constexpr double PI3 = PI2;

const int i = 100;
int arr[i]; // variable length array declaration not allowed at file scope

// const auto func(int x, int y) {
constexpr auto func(int x, int y) { // use constexpr striclty in function5j 
    return x + y + 12.3f;
}


int main(int argc, const char *argv[]) {
    std::cout << "Hell0, constexpr \n";
    auto res = func(3, 2);
    std::cout << res << std::endl;
    return 0;
}
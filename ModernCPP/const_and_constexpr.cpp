#include<iostream>

const double PI1 = 3.141592653589793;
constexpr double PI2 = 3.141592653589793;
constexpr double PI3 = PI2;

const int i = 100;
int arr[i]; // variable length array declaration not allowed at file scope

// const auto func(int x, int y) {
const auto func(const int x, const int y) { // use constexpr striclty in function5j 
    return x + y;
}
constexpr auto func_constexpr(int x, int y) { // use constexpr striclty in function5j 
    return x + y;
}

int i, j;

// int array [func(10, 20)]; // variable length array declaration not allowed at file scope
int array1 [func_constexpr(10, 20)];
// int arra2[func_constexpr(10, rand())]; // variable length array declaration


// const and constexpr in classes
class Test3 {
    public:
    int value;

    constexpr int getValue() const {
        return value;
    }

    constexpr Test3(int value) : value(value) {}
};

constexpr Test3 test( 100 );
int arr_5 [test.getValue()];

int main(int argc, const char *argv[]) {
    // std::cout << "Hell0, constexpr \n";
    // auto res = func(3, 2);
    // std::cout << res << std::endl;

    // int val = getValue<false>();
    
    return 0;
}
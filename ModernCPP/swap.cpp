#include<iostream>

int main() {
    int a = 10;
    int b = 20;
    
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::swap(a,b);

    std::cout << "-------AfterSwapping---------" << std::endl;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;


    return 0;
}
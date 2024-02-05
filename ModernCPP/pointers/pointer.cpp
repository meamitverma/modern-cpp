#include<iostream>

int main() {

    int store[6] = {10,20,30,40,50};

    std::cout << (*(store + 1)) << std::endl;

    return 0;
}
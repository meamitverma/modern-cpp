#include<iostream>


int main() {
    int x = 10;
    int y{20}; // initializer _list
    // int z[] = {10,20,30,40};

    // range for loop
    //            unnamed namedspace
    for (int x : {11, 22, 33, 44, 55}) {
        std::cout << x << std::endl;
    }

    return 0;
}
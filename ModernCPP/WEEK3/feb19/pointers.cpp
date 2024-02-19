#include<iostream>
#include<vector>
#include<memory>


int main() {

    int i = 10;
    // int *p = new int[10];
    int *p = &i;

    std::cout << *p << std::endl; // not allowed according to misra guidelines
    



    int a = 10;
    int b = 20;
    int c = 30;

    // legacy way of using pointers
    // std::vector<int*> vecPtr{&a, &b, &c};
    std::vector< std::reference_wrapper<int> > vecPtr{a, b, c};
    for (auto ptr: vecPtr) {
        // (*ptr) += 5;
        ptr.get() += 5;
    }
    for (auto ptr : vecPtr) {
        // std::cout << (*ptr) << std::endl;
        std::cout << ptr.get() << std::endl;
    }



    return 0;
}
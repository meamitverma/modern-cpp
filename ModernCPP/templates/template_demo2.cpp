#include<iostream>


template<typename T>
auto add(T a, T b) {
    return a + b;
}

int main() {

    auto res = add(3, 5.3f);
    std::cout << res << std::endl;

    return 0;
}
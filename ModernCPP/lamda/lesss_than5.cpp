#include<iostream>

const auto less_than = [](auto x) {
    return [x](auto y) {
        std::cout << " y " << y << " x "  << x << std::endl;
        return y < x;
    };
};

int main(void) {
    auto less_than_five = less_than(5);
    std::cout << " TRUE " << less_than_five(22) << std::endl;
    std::cout << less_than_five(3)  << std::endl;

    std::cout << less_than_five(10) << std::endl;

    return 0;
}
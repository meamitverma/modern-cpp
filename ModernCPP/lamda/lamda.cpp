#include <iostream>

// [&] (x, y) int {
//     int sum = x + y;
//     return sum;
// }

// template<typename T1, auto T2>
// auto add(T1 a, T2 b) {
//     // return (a + b);
// }

void add(auto i)
{
    std::cout << "auto i " << i << std::endl;
}

constexpr auto sum = [](const auto &a, const auto &b)
{
    return a + b;
};

int main()
{

    int i = 10;
    // auto k;

    // int x = 10;
    // auto add_five = [x](int a) -> int
    // { return a + x; }; // Captures x by value
    // int result = add_five(7);

    // std::cout << result << std::endl;

    std::cout << sum(2,3) << std::endl;


    return 0;
}
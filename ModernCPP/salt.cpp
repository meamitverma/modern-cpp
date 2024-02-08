#include<iostream>
#include<string_view>
#include<functional>
#include<array>
#include<algorithm>

// functional composition -> can take lambdas,


int main() {

    std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    auto print = [ &s ](std::string_view const rem) {
        for (auto a : s) {
            std::cout << a << " ";
        }
        std::cout << ":" << rem << std::endl;
    };

    std::sort(s.begin(), s.end());
    print("Sorted with default operator <");

    std::sort(s.begin(), s.end(), std::greater<int>()); // sending all the data to greater function
    print("Sorted with greater api");

    // function object
    struct {
        bool operator()(int a, int b) const {
            return a < b;
        }
    } customLess;
    std::sort(s.begin(), s.end(), customLess); // data is passed to the customless structure
    print("Sorted with customLess struct ");


    std::sort(s.begin(), s.end(), [](int a, int b) { return a > b;});
    print("Sorted with lambda");

    return 0;
}
#include <iostream>
#include <variant>
#include <vector>

using var_t = std::variant<int, std::string>;

// struct PrintInt
// {
//     void operator()(int i)
//     {
//         std::cout << i << std::endl;
//     }
// };

// struct PrintString
// {
//     void operator()(std::string str)
//     {
//         std::cout << str << std::endl;
//     }
// };

template <typename... Ts>
struct Print : Ts...
{
    using Ts::operator()...;
};

template <typename... Ts>
auto makePrint(Ts... ts)
{
    return Print<Ts...>(ts...);
}

int main()
{
    std::cout << "Lambda Overload !\n"
              << std::endl;
    std::vector<var_t> vars = {1, 2, "Hello World", "Bangalore", 4, 5, 6};

    // Print p;
    for (auto &v : vars)
    {
        std::visit(
            makePrint(
                [](int i){ std::cout << i << std::endl; },
                [](std::string str){ std::cout << str << std::endl; }),
            v);
    }

    return 0;
}
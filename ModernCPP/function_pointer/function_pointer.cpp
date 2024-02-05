#include <iostream>
#include <type_traits>

// constant function
constexpr auto add(const int a, const int b) -> int
{
    return a + b;
}

// declare a function pointer
// (*)();
// Place holder or Callback.
int (*MyFnPtr)(int x, int y) = add;

// passing function reference as argument
// functional composition
// standard way of declaring a function
constexpr auto resultOfCalculation(int (*OP)(int, int), int x, int y) -> decltype((*OP)(x, y))
{
    return (*OP)(x, y);
}

// bad code
template <typename FN, typename T1, typename T2>
constexpr auto resultOfCalculation(
    const FN &OP,
    const T1 &x,
    const T2 y) -> decltype((*OP)(x, y))
{
    return OP(x, y);
}

// third version
template <typename T>
struct is_variable : std::is_object<T>
{
};

template <typename FN, typename T1, typename T2>
constexpr auto resultOfCalculation_3(
    const FN &OP,
    const T1 &x,
    const T2 y) -> std::enable_if_t<std::is_invocable_v<FN, T1, T2> && // check if this is a function
                                        is_variable<T1>::value &&
                                        is_variable<T2>::value,

                                    decltype((*OP)(x, y))

                                    >
{ // to check if it is a function or not -> invokable checks for if the passed argument is a function or not and not a random pointer of a variable

    return OP(x, y); // invokable
}

template<typename... Args>
auto add2(Args... args) -> int{
    return (args +...);
}

// version 4
template <typename FN, typename... Args>
constexpr auto resultOfCalculation_4(
    const FN &OP,
    Args... args
    ) -> decltype(OP( args... ))
{

    return OP( args... ); // invokable
}




// compose(add, mul, sub, div, 12, 32);

int main()
{

    // outdated way of calling
    std::cout << "Sum of funptr = " << MyFnPtr(12, 34) << std::endl;

    int res = resultOfCalculation(add, 2, 5);
    std::cout << res << std::endl;

    float res2 = resultOfCalculation(add, 300.2, 300);
    std::cout << res2 << std::endl;

    // int res3 = resultOfCalculation_3(add, 200, 500);
    // std::cout << res3 << std::endl;

    int res4 = resultOfCalculation_4(add2<int, int, int, int>, 100, 200, 300, 400) ;
    std::cout << res4 << std::endl;

    return 0;
}
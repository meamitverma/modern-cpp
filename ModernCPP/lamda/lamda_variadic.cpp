#include<iostream>

void print(){}

// variadic
template<typename First, typename... Rest>
void print(const First &first, const Rest... args) {
    std::cout << first << std::endl;
    print(args...);
}

// fold expression
template<typename ...T>
auto doSomething(T... t) {
    return (t +...);
};

// Phase II
// template<typename ...T> // dont write template for lambda
constexpr auto add = []<class... T>(T... args) {
    return (args +...);
};

int main() {

    // print<void(auto...)> variadic_lamda = [](auto... args){ // here the auto if function pointer->nullptr_t
    //     print(args...);
    // };

    // print<void(auto...)> variadic_lamda = [](auto... args){ // here the auto if function pointer->nullptr_t
    //     print(args...);
    // };

    // (*print()) =varidic_lamda = [](auto... args){ // here the auto if function pointer->nullptr_t
    //     print(args...);
    // };

    // void(*)(auto) variadic_lamda = [](auto... args){ // here the auto if function pointer->nullptr_t
    //     print(args...);
    // };

    // calling variadic through lambda
    auto variadic_lamda = [](auto... args){ // here the auto if function pointer->nullptr_t
        print(args...);
    };

    variadic_lamda(1, "KPIT", 20, "IT");





    // calling fold expression through lamda
    std::cout << "Do something fold lamda" << add(10,20,30,40,50,60) << std:: endl; 




    // print(1, "Apple", 20, "Samsung");

    return 0;
}
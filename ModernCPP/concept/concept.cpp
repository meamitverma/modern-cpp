#include<iostream>
#include<type_traits>

// Concept: ;hj
// Phase 1:
template<typename T>
concept Integral = std::is_integral<T>::value;

template< Integral T >
T gcd(T a, T b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

Integral auto gcd(Integral auto a, Integral auto b) {
    if ( b == 0) return;
    else 
        return 
        gcd(b, a % b);
}


template <typename T>
concept Addable = requires(T a, T b) {
    {a + b} -> std::same_as<T>;
};

template<Addable T>
T addTwoValues(T a, T b) {
    return a + b;
}

int main() {

    int a = 10, b = 20;
    std::cout << "gcd: " << gcd(a, b) << std::endl;

    return 0;
}
#include<iostream>

template<typename T>
void print(const T &t) {
    std::cout << " In me " << t << std::endl;
}

template<typename First, typename... Rest>
void print(const First &first, const Rest &...rest) {

    std::cout << __PRETTY_FUNCTION__ << std::endl;

    std::cout << first << ", " ;
    print(rest...);
}

int main() {


    print("First", 1, "Second", 2, "Third", 3);

    return 0;
}


#include<iostream>

const std::string message = "I'm here";
const std::string& foo() {
    return message;
}

auto& increment(int &a) {
    a++;
    return a;
}

int  main(int argc, const char *argv[] ){

    std::cout << "auto decltupe tupe traits functional composition\n";

    const auto f1 = foo();
    decltype(foo()) f2 = foo(); // best way
    decltype(auto) f3 = foo();

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;
    
    
    int a = 100;
    int &y = increment(a);
    std::cout << "a: " <<  a << " y: " << y << std::endl;

    return 0;
}
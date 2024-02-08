#include<iostream>

int global = 10;
auto testSpeedString = [](int speed)-> std::string { 
    if(speed > 100) {
        return "You are a super fast driver";
    }
    else {
        return "You are a Composed Driver";
    }
};

int main() {

    std::cout << global << std::endl;
    // = take the values from inside the function
    // noexcept -> will not throw exception, helps compiler to compile faster
    auto foo = [=] mutable noexcept { ++global;};
    foo();
    std::cout << global << std::endl;
    const auto increaseGlobal = []() noexcept { ++global; };
    increaseGlobal();
    std::cout << global << std::endl;


    // Phase II
    auto str = testSpeedString(10);
    std::cout << str << std::endl;

    return 0;
}
#include<iostream>
// higher order function
// parallel execution

auto makeMeADeveloper(const std::string &name) {

    int age = 21;

    // return [&name, age](){
    // return [&, age, id](){
    return [ = ]() // global capture list
    {
        std::cout << "I am a developer, my name is " << name <<  " and my age is " << age <<std::endl;
    };
}   


int main(int argc, char *argv[]) {

    auto sayName { makeMeADeveloper("Amit") };
    sayName();

    return 0;
}
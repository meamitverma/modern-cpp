#include<iostream>

class MyClass {
    public:
    int data;

    MyClass(int &&value) {
        data = value;
        std::cout << "Move constructor in MyClass called" << std::endl;
    }

    ~MyClass() = default;
};

int myFunction() { return 123; }

MyClass createObject() {
    std::cout << "Creating object" << std::endl;
    MyClass obj(5);
    return obj; // rValue constructor
}


int main() {

    int value = 1234;
    MyClass obj(value + 1); // rValue
    std::cout << "obj.data " << obj.data << std::endl;

    // rValue MyClass obj
    MyClass obj2(myFunction());
    std::cout << "--------------createObject()---------------" << std::endl;
    MyClass obj6 = createObject();

    return 0;
}
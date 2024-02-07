#include<iostream>
using namespace std;

int foo() { return 10;}
std::string myCat = "Persian Cat";
std::string makeCat() {
    // thread th();
    return myCat;
}

class MyVector {

    public:

    // constructor
    MyVector(int i) : size(i){
        std::cout<<"---> Landed at regular constructor " << std::endl;
        elements = new int[i];
        for (int j = 0; j < i; j++) {
            elements[j] = j;
        }
    }

    // Destructor
    ~MyVector() {
        std:cout << "---> Landed at destructor" << std::endl;
        delete[] elements;
    }

    // Copy constructor
    MyVector(const MyVector &other) : size(other.size) {
        std::cout << "---> Landed at copy constructor..." << std::endl;
        elements = new int[other.size];

        for (int i = 0; i <= other.size; i++) {
            elements[i] = other.elements[i];
        }
    }

    // rValue constructor -> modern cpp
    MyVector(MyVector&& other) : size(0), elements(nullptr) {
        std::cout << "---> Landed at rVlaue Constructor" << std::endl;

        // elements = other.elements;
        // size = other.size;

        // // lets clean up the memory
        // other.elements = nullptr;
        // other.size = 0;

        // Phase II
        // swap(other)
        std::swap(elements, other.elements);
        std::swap(size, other.size);
    }

    

    int& getSize() {
        return size;
    }
    
    int &operator[](int index) {
        std::cout << "---> Operator[](int index)[]";
        return elements[index];
    }

    // private:
    int size;
    int *elements;
};

int *begin(MyVector &v) {
    std::cout << "begin()" << std::endl;
    return v.elements;
}

int *end(MyVector &v) {
    std::cout << "end()" << std::endl;
    return v.getSize() != 0 ? &v[0] + v.getSize() : nullptr;
}

int main(int argc, char *argv[]) {

    std::cout << "Expression lValue rValue !\n";
    int *arr; int  *p; int x; int y;

    // lValue

    int i = 10;
    x;
    *p;
    arr[0];


    // rValue

    foo();
    
    12;
    x + y;

    int& lValue = x;
    int&& rValue = 30;

    const int& L_r_value = 23; // do not get const infront of l value

    nullptr_t myVar; // prValue
    // NULL xyz; // (void*)0


    std::string s("Cat");
    std::string s2(s); // copy constructor.. // move constructor
    std::string s3(makeCat());
    std::string s4(std::move(makeCat()));

    MyVector v1(10);
    MyVector v2(v1);// 
    MyVector v3(static_cast<MyVector&&>(v1));

    for (auto x : v2) {
        std::cout << x << " ";
    }

    MyVector v4(std::move(v2));
    
    for (auto x : v4) {
        std::cout << x << " X ";
    }


    return 0;
}
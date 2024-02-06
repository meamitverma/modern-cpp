#include<iostream>
using namespace std;

int foo() { return 10;}
std::string myCat = "My Cat";
std::string makeCat() {
    // thread th();
    return myCat;
}

int main(int argc, char *argv[]) {

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

    

    return 0;
}
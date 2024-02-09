#include<bits/stdc++.h>
using namespace std;

template<typename T>
requires requires(T value) {
    {value.incement()}->same_as<void>;}
    void performAction(T value) {
        value.increment();
    }

    class MyClass{
        public:
        void increment(){
            cout << "Incrementing...";
        }
    };


int main() {

    MyClass obj;
    performAction(obj);
    
    return 0;
}
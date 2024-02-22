#include<iostream>
#include<vector>

class A {
    public:
    int mx;
    double my;
    A(int a, int b) : mx(a), my(b){}
};

class B {
    public:
    int mx;
    double my;
    B(int x, int y) : mx(x), my(y){}

    B(const std::initializer_list< int >& v) {
        mx = *(v.begin());
        my = *(v.end() + 2);
    }
};

class MyNumber {
    std::vector<int> myvec;
    public:
    MyNumber(const std::initializer_list<int >& v) {
        myvec.insert(myvec.end(), v.begin(), v.end());
    }
    // template<typename... T>
    // MyNumber(const std::initializer_list<int >& v) {
    //     myvec.insert(myvec.end(), v.begin(), v.end());
    // }

    void print() {
        for (auto itm : myvec) {
            std::cout << itm << " ";
        }
        std::cout << std::endl;
    }


};

int main() {

    // A a(10, 20);
    A a{10, 20}; // uniform intialization is also called as aggregate initialization

    B b {23,23,234,24};


    MyNumber m{1,2,3,4,5,6,6};
    MyNumber myNumber{1,23};
    myNumber.print();
    m.print();

    auto[aa, bb] = a;
    std::cout << aa << " " << bb << std::endl;

    return 0;
}
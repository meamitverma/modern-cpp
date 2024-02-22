#include<bits/stdc++.h>
#include<memory>

using namespace std;

class A {

};
void fun(int a){
    cout<<"---"<<a;
}
int main() {
    // std::unique_ptr<Foo>p2 (std::move(p1));
    // if(p1)p1->foo();
    // auto i{10};
    auto say{fun}; say(10);
    // cout<<i;
    return 0;
}
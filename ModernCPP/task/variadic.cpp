#include <iostream>

template<typename T1, typename T2>
auto add(T1 t1, T2 t2){
    std::cout << "Add: " << t1 + t2 << std::endl;
}

template<typename T1, typename T2>
auto sub(T1 t1, T2 t2){
    std::cout << "Sub: " << t1 - t2 << std::endl;
}

template<typename T1, typename T2>
auto mul(T1 t1, T2 t2){
    std::cout << "Mul: " << t1 * t2 << std::endl;
}

template<typename T1, typename T2>
auto div1(T1 t1, T2 t2){
    std::cout << "Div: " << t1 / t2 << std::endl;
}

template<typename T1, typename T2, typename T3>
void calc(T1 t1, T2 t2, T3 t3){
    t1(t2, t3);
}

template<typename T1, typename T2, typename T3, typename ...T4>
void calc(T1 t1, T2 t2, T3 t3, T4 ...t4){
    t1(t2, t3);
    calc(t4...);
}

int main(){
    calc(add<int,int>,2,3, sub<int,int>,7,5, mul<int,int>,3,6, div1<int,int>,40,5);

    return 0;
}
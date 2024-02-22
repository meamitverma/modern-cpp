#include<iostream>
#include<functional>
#include<tuple>
 
int add(int a, int b){
    return a+b;
}
float multiply(float a, float b){
    return a*b;
}
std::string concatenate(const std::string& str1, const std::string& str2){
    return str1+str2;
}
 
template<typename...Funcs, typename...Args>
void printResult(const std::tuple<std::function<Funcs>...>&
                tuple, Args&&...args){
        auto invokeFunction = [&](auto&& func){
            using FunctionType = std::decay_t<decltype(func)>;
            if constexpr(std::is_invocable_v<FunctionType>){
                std::cout<<"Result: "<<func()<<std::endl;
            } else{
                std::cout<<"Error: Invalid function "<<std::endl;
            }
        };
        std::apply([&](auto&&...funcs){
            (invokeFunction(funcs), ...);
        },tuple);
};
int main(){
    //compose a tuple with function pointers
    std::tuple< std::function<int()>, std::function<float()>,
        std::function<std::string()>> funcTuple(
        [](){ return add(3,4);},
        [](){ return multiply(2.5f, 6.3f); },
        [](){ return concatenate("Hello", "World");}
    );
    //call the functions using tuple
 
    printResult(funcTuple); //call each function with no arguments
 
    return 0;
}
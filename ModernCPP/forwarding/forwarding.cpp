#include<iostream>


void funda(int &&avar) {
    std::cout << "R- Value overload called " << avar << std::endl;
}
void funda(int &avar) {
    std::cout << "L - value overload called " << avar << std::endl;
}

template<typename T>
T my_forward(typename std::remove_reference<T>::type &param) {
    std::cout << "My forward " << static_cast<T>(param) << std::endl;
    return static_cast<T>(param);
}

template<typename T>
void call_funda(T&& parg) // Argument universal reference..
{
    // funda(parg); 
    // funda(std::move(parg)); // converts to rvalue forcefully
    // funda (my_forward<T>(parg));
    funda(std::forward<T>(parg));
}

int main(int argc, const char *argv[]) {

    std::cout << "L value r value \n";
    int myVar = 5;
    call_funda(myVar); // l value overload
    call_funda(4); // rvalue

    return 0;
}
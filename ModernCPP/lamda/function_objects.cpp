#include <iostream>



class Anonymous {
    public:
    template<typename T1, typename T2>
    constexpr auto operator () (const T1 a, const T2 b) {
        return a + b;
    }
};

// [](){}; // lamda

int main()
{

    std::cout << "Function Objects" << std::endl;
    Anonymous an;
    std::cout << "Returned from function object " << an(5, 2) << std::endl;

    return 0;
}
#include <iostream>
#include <variant>
#include <vector>
#include <typeinfo>

int main()
{
    std::vector<std::variant<char, long, float, int, double, long long>> 
        vecVariant = {5, '2', 5.4, 1001ll, 2011l, 3.5f, 2017};

    for (auto &v : vecVariant) {
        // std::visit( lambda, v );
        //             visitable, visitor
        // visitor is visiting the v

        auto visitor = []( auto arg ){std::cout << arg << " " << typeid(arg).name() <<  std::endl;};
        // auto visitor = []( auto arg ){std::cout << typeid(arg).name() << " " << std::endl;};
        std::visit( visitor , v );

    }

    return 0;
}
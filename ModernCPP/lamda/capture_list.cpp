#include <iostream>

// lambda composition

int main()
{

    const auto print = [](const char *str, int x, int y)
    {
        std::cout << str << " : " << x << " " << y << std::endl;
    };

    int x = 1, y = 1;
    print("In main... ", x, y);

    // lambda composition
    auto foo = [x, y, &print]() mutable
    {
        ++x;
        ++y;
        print("In foo() ", x, y);
    };

    foo();
    print("In main ", x, y);

    return 0;
}
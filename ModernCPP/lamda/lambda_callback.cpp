#include<iostream>
#include<functional>

// std::function<void(int)> fun;

void callwithNumber( void(*bar)(int)) {
    bar(10);
}

int main() {
    // callwithNumber();
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    struct {
        using f_ptr = void(*)(int);
        void operator()(int s) const {
            return call(s);
        };
        operator f_ptr() const {
            return &call;
        }

        private:
        static void call(int s) {
            std::cout << s << std::endl;
        }
    } bar;

    callwithNumber(bar);
    callwithNumber([](int x){ std::cout << x << std::endl; });

    return 0;
}
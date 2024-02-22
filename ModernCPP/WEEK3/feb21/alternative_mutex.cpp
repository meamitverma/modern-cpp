// using singleton
#include<iostream>
#include<mutex> // to impliment


class Singleton {
    public:
    static Singleton& getInstance() {
        std::call_once(flag_, [](){ 
            std::cout << "At getInstance()" << std::endl;
            instance_ = new Singleton; 
        });
        return *instance_;
    }

    private:
    Singleton() {}
    static Singleton* instance_;
    static std::once_flag flag_;
};

Singleton* Singleton::instance_ = nullptr;
std::once_flag Singleton::flag_;

int main() {

    std::cout << "Singleton once_flag\n";
    Singleton& s1 = s1.getInstance();
    Singleton& s2 = s1.getInstance();
    Singleton& s3 = s1.getInstance();

    if ( &s1 == &s2 ) {
        std::cout << "Singleton works..." << std::endl;
    }

    return 0;
}
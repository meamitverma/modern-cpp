#include<iostream>
#include<tuple>
// Feb 7

std::tuple<int, std::string, double > f() {
    int i {108};
    std::string s{"Some text"};
    double d{12.22};

    // return {i, s, d};
    return std::make_tuple(i, s, d);
}

void myTuple() {
    typedef std::tuple<int, char, float> tp;
    tp t1(100, 'A', 10.11);
    tp t2(200, 'B', 200.22);
    tp t3 = std::make_tuple(300, 'C', 300.33);

    // Display all the stored elements
    std::cout << std::get<0>(t1) << std::endl;
    std::cout << std::get<1>(t1) << std::endl;
    std::cout << std::get<2>(t1) << std::endl;


    int i = get<0>(t1);
    std::cout << "From tuple index 0 " << i << std::endl;

    int first;
    char second;
    float third;

    std::tie(first, second, third) = t2;
    std::cout << "Display set t2 " << first << std:: endl;
    std::cout << "Display set t2 " << second << std:: endl;
    std::cout << "Display set t2 " << third << std:: endl;


    std::tie(first, second, third) = std::make_tuple(300, '2', 123.33);
    std::cout << "Display set t3 " << first << std:: endl;
    std::cout << "Display set t3 " << second << std:: endl;
    std::cout << "Display set t3 " << third << std:: endl;

}

int main(int argc, char *argv[]) {   

    // structural binding
    auto [x, y, z] = f();

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;

    myTuple();
    

    return 0;
}
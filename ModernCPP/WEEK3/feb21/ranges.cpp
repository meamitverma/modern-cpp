#include<iostream>
#include<ranges>
#include<vector>
#include<type_traits>

auto range(int start, int end) {
    return std::views::iota(start, end);
}

struct MyRange {
    int data [ 5 ] = {10, 20, 30, 40, 50};

    // auto begin() const -> decltype( std::begin( data ) ) {
    //     return std::begin(data);
    // }
    // auto end() const -> decltype( std::end( data ) ) {
    //     return std::end( data );
    // }

    
};


template< class T >
concept Range = requires( T& t) {
    std::ranges::begin( t );
    std::ranges::end( t );
};

template< Range R >
void printRange( const R& r) {
    for ( const auto& value : r) {
        std::cout << "R:" << value << " ";
    }
}

int main() {

    std::vector< int > numbers = {1, 2, 3, 4, 5};



    std::cout << "Range \n";

    // ranges are pre populated 
    for (int i : std::views::iota(1,10)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    // lazy way of execution
    // only when asked
    for (int i : std::ranges::iota_view(1,10)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int n : range(1, 20)) {
        std::cout << n << " ";
    }
    std::cout << std::endl;


    std::cout << "------vector elements-------" << std::endl;
    for ( int n : numbers   ) {
        std::cout << n << " ";
    }
    std::cout << std::endl;


    std::cout << "------struct elements-------" << std::endl;
    MyRange myRange;
    for ( int n : myRange.data ) { // 'MyRange' does not refer  to a value
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // printRange<MyRange>(myRange);
    printRange(myRange.data);

    return 0;
}
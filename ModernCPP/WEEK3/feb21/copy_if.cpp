#include<iostream>
#include<vector>
#include<ranges>
#include<algorithm>

auto isEven = [](int num) { return num % 2 == 0; };

// BAD WAY xxxxxxxxxx
// void reverse() {
//     const std::vector numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   
//     std::vector<int> temp;
//     std::copy_if( begin(numbers), end(numbers), std::back_inserter(temp), isEven );
    
//     // for ( auto& n : temp) {
//     //     std::cout << n << " ";
//     // }

//     // DROP A NUMBER
//     std::vector<int> temp2(begin(temp) + 1, end(temp));
//     // for ( auto& n : temp2) {
//     //     std::cout << n << " ";
//     // }



//     // REVERSE THE NUMBERS
//     for (auto iter = rbegin(temp2); iter != rend(temp2); iter++) {
//         std::cout << *iter << " ";
//     }

//     std::cout << std::endl;
// }


// BETTER WAY
// void reverse() {
//     const std::vector numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   
//     std::vector<int> temp;
//     std::copy_if( begin(numbers), end(numbers), std::back_inserter(temp), isEven );
    
//     // for ( auto& n : temp) {
//     //     std::cout << n << " ";
//     // }

//     std::vector<int> temp2(begin(temp) + 1, end(temp));
//     // for ( auto& n : temp2) {
//     //     std::cout << n << " ";
//     // }



//     // DROP A NUMBER
//     // REVERSE THE NUMBERS
//     std::cout << "Better way of coding..." << std::endl;
//     auto rv = std::views::reverse(std::views::drop(std::views::filter( numbers, isEven), 1));

//     std::cout << std::endl;
// }

// BEST WAY
void reverse_2() {
    namespace rv = std::ranges::views;
    std::vector< int > nums { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 ,89};

    //  filter even numbers | reverse | taking
    auto ans = nums | rv::filter( isEven ) | rv::reverse | rv::take(2);

    for (auto n : ans) {
        std::cout << " : " << n << " ";
    }

    std::cout << std::endl;
}


int main() {
    // reverse();
    reverse_2();
    return 0;
}
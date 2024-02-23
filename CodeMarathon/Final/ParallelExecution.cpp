#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<execution>

int numElems = 1000;

auto execute(const std::string &msg) {
    return [ msg ]()
    {
        std::cout << msg <<std::endl;
    };
} 

int main () {
    std::vector<int> nums = {5, 2, 4 ,1, 3};
    for (int i = 0; i < numElems; ++i) {
        nums.emplace_back(i * 10);
    }
    
    std::cout << "Parallel Execution" << std::endl;

    // Start the timer
    auto startTime = std::chrono::high_resolution_clock::now();

    std::for_each(std::execution::par, nums.begin(), nums.end(), [](int &num){num *= 2;});

    // Stop the timer
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds> (endTime - startTime);

    // Print the modified vector
    std::cout << "Modified vector: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Print the execution time
    std::cout << "Execution time: " << duration.count() << " microseconds." << std::endl;
    
    return 0;   
}
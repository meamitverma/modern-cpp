#include<iostream>
#include<vector>
#include<future>
#include<functional>
#include<algorithm>
#include<execution>

void execute(const std::string &msg) {
    std:: cout <<  msg << std::endl;
} 

int main () {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    std::for_each(std::execution::par, nums.begin(), nums.end(), [](int &num){
        execute("Thread " + std::to_string(num));
    });

    std::future<void> asyncThread = std::async(std::launch::async, execute, "thread");
    asyncThread.wait();


    return 0;   
}




// write a lambda code to demonstrate the use of parallel execution using higher order functinos with an async thread



/*

#include <iostream>
#include <future>
#include <vector>
#include <algorithm>

int main() {
    // Function to perform some computation
    auto compute = [](int x) {
        // Simulating some time-consuming task
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        return x * x;
    };

    // Create a vector of integers
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Use async to perform computation in parallel
    std::vector<std::future<int>> futures;
    for (int x : data) {
        futures.push_back(std::async(std::launch::async, compute, x));
    }

    // Wait for all async tasks to finish and retrieve results
    std::vector<int> results;
    for (auto& future : futures) {
        results.push_back(future.get());
    }

    // Display results
    std::cout << "Original data: ";
    for (int x : data) {
        std::cout << x << " ";
    }

    std::cout << "\nSquared values: ";
    for (int result : results) {
        std::cout << result << " ";
    }

    return 0;
}

#include <iostream>
#include<future>

using namespace std::chrono;

typedef long ull;

ull EvenSum = 0;
ull OddSum = 0;

ull findEven(ull start, ull end) {
    ull EvenSum = 0;

    std::cout << "Find Even Async Thread ID: " << std::this_thread::get_id() << std::endl; 

    for (ull i = start; i <= end; i++) {
        if (i % 2) {
            EvenSum += i;
        }
    }

    return EvenSum;
}

ull findODD(ull start, ull end) {
    ull OddSum = 0;

    std::cout << "Find Odd Async Thread ID: " << std::this_thread::get_id() << std::endl; 

    for (ull i = start; i <= end; i++) {
        if (!(i % 2)) {
            OddSum += i;
        }
    }

    return OddSum;
}


int main()
{
    std::cout << "Async Deferred threads..\n" << std::endl;
    ull start = 0, end = 1900000000;

    // Co routines.. Faster..
    auto startTime = high_resolution_clock::now();

    std::cout << "Async Thread in Main ID:" << std::this_thread::get_id() << std::endl;

    // ------------------code starts
        // std::future<ull> EvenSum = std::async(std::launch::async, findEven, start, end);
        // std::future<ull> EvenOdd = std::async(std::launch::async, findODD, start, end);

        std::future<ull> EvenSum = std::async(std::launch::deferred, findEven, start, end);
        std::future<ull> EvenOdd = std::async(std::launch::deferred, findODD, start, end);
    // ------------------code ends

    std::cout << "Just for fun..." << std::endl;

    std::cout << "Even sum : " << EvenSum.get() << std::endl;
    std::cout << "Odd sum : " << EvenOdd.get() << std::endl;
    std::cout << "Job done... " << std::endl;


    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    std::cout << "Sec: " << duration.count() / 1000000 << std::endl;

    return 0;
}



*/
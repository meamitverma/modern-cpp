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
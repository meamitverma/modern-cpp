#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>

std::mutex g_mutex;
bool g_ready = false;
int  g_data  = 0;

int produceData() {
    int randomNumber = rand() % 1000;
    std::cout << "Produced data: " << randomNumber << std::endl;
    return randomNumber;
}

void consumeData(int data) {
    std::cout << "Received Data: " << data << std::endl;
}


// ----------Templates----------
void consumer() {
    while ( true ) {

        while ( !g_ready ) {
            // waiting for the producer to prduce something
            std::this_thread::sleep_for(std::chrono::seconds( 3 ));
        }

        // lock the section
        std::unique_lock< std::mutex > ul( g_mutex );

        consumeData( g_data );

        g_ready = false;
        ul.unlock();

    }
}

void producer() {

    while ( true ) {
        std::unique_lock< std::mutex > ul( g_mutex );
        g_data = produceData();
        g_ready = true;
        ul.unlock();

        while ( g_ready ) {
            // sleep for a sec...
            std::this_thread::sleep_for(std::chrono::seconds( 1 ));
        }
    }

}

void consumerThread() {
    consumer();
}

void producerThread() {
    producer();
}

int main() {

    std::cout << "Producer Consumer Threads \n";

    std::thread t1(consumerThread);
    std::thread t2(producerThread);

    // consumer should wait unitl producer is not finished

    t1.join();
    t2.join();
    
    return 0;
}
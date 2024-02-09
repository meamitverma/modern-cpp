#include<iostream>
#include<vector>

void ForEach(const std::vector<int> &values, void (*funPtr)(int)) {
    // Turn the net on
    // Download the data from server...
    // A service/a thread/Async thread...
    for (int value : values) {
        std::cout << "about to call lambda {}" << std::endl;
        funPtr(value); // it's a call back()
    }

    // shut the network down
}

int main() {
    
    std::vector<int> values = {1,2,3,4,5};
    ForEach(values, [](int value){std::cout << "Value : " << value << std::endl;});

    return 0;
}
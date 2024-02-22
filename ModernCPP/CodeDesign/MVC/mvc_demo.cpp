#include<iostream>

// Model
class CounterModel {

    public:
    // constructor
    CounterModel() : count (0) {}

    // getter
    constexpr int getCount() const {
        return count;
    }

    void increment() {
        count++;
    }

    private:
    int count;
};

// View -> only to display the data
class CounterView{
    public:
    void displayCount(int count) const {
        std::cout << "Count : " << count << std::endl;
    }
};


// Controller
class CounterController {
    public:
    CounterController (CounterModel &model,  CounterView &view) : model(model), view(view) {}

    void incrementCounter() {
        model.increment();
        // updateViews(); // bad call-> contaminated the code
    }

    void updateViews() const {
        view.displayCount( model.getCount() );
    }

    private:
    CounterModel model;
    CounterView view;   
};

int main() {

    std::cout << "MVC Framework\n";

    CounterModel model;
    CounterView view;
    CounterController controller(model, view);

    // Initial display
    controller.updateViews();
    controller.incrementCounter();
    controller.incrementCounter();
    controller.incrementCounter();


    // Display the updated view
    // controller.updateViews(); // bad call -> controller should automatically calls view on update


    return 0;
}
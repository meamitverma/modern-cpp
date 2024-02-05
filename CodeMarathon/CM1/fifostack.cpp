#include<iostream>
#include<vector>

class iStack {
public:
    virtual int top() = 0;
    virtual void push(int num) = 0;
    virtual int pop() = 0;
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
};

class Stack : public iStack {
private:
    std::vector<int> arr;
    int tos;
    int size;

public:
    Stack() : tos(-1), size(0) {}

    int top() override {
        if (isEmpty()) return -1;
        return arr[tos];
    }

    void push(int val) override {
        arr.emplace_back(val);
        tos++;
        size++;
    }

    int pop() override {
        if (isEmpty()) return -1;
        int val = top();
        arr.pop_back();
        tos--;
        size--;
        return val;
    }

    bool isEmpty() override {
        return size <= 0 || tos < 0;
    }

    int getSize() override {
        return size;
    }
};

class FIFOStack {
public:
    virtual void enqueue(int val) = 0;
    virtual int dequeue() = 0;
};

class Queue : public FIFOStack {
private:
    Stack stack1;
    Stack stack2;

public:
    void enqueue(int val) override {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }

        stack1.push(val);

        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
    }

    int dequeue() override {
        return stack1.pop();
    }
};

class User{
    private:
    FIFOStack *fifostack;

    public:
    User(FIFOStack *_fifostack) {
        fifostack = _fifostack;
    }

    void enqueue(int num) {
        fifostack->enqueue(num);
    }
    int dequeue() {
        return fifostack->dequeue();
    } 
};


int main() {
    // iStack *stack = new Stack();
    FIFOStack *stack = new Queue();
    User q(stack);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(7);

    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;


    return 0;
}

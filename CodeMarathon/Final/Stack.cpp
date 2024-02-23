#include<iostream>
#include<vector>

// STACK INTERFACE
class iStack {
public:
    virtual void push(int val) = 0;
    virtual int pop() = 0;
    virtual int top() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
};

// CONCRETE STACK CLASS
class Stack : public iStack {
public:
    void push(int val) {
        arr.emplace_back(val);
        tops++;
    }

    int top() {
        if (!isEmpty()) 
            return arr[tops];
        
        return -1;
    }

    int pop() {
        if (isEmpty()) return -1;

        int temp = arr[tops];
        
        arr.pop_back();
        tops--;
        
        return temp;
    }

    bool isEmpty() {
        return tops == -1;
    }

    int size() {
        return tops + 1;
    }

private:
    std::vector<int> arr;
    int tops = -1;
};

// BUGFIX -> by composing stack class
class BugFix {
public:
    BugFix (Stack* _stack) : stack(_stack) {}

    // assume there is bug on pop
    int pop() {
        // i dont want to pop the last element
        if ( stack->size() <= 1 ) {
            std::cout << "Stack has one element, dont pop the last element : " << stack->top() << std::endl;
            return stack->top();
        }

        return stack->pop();
    }

private:
    Stack* stack;
};

int main() {

    Stack stack;
    stack.push(2);
    stack.push(3);

    std::cout << stack.pop() << std::endl;

    BugFix bug1(&stack);
    bug1.pop();

    return 0;
}
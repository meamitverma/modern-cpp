#include<iostream>
using namespace std;

class Stack {
    private:
    int store[6];

    public:
    int tos = -1;

    Stack() { tos = 0; }
    void push( int val) {
        store[++tos] = val;
    }

    int pop();

    int atTop() {
        tos--;
        return store[tos++];
    }
};

int Stack:: pop() {
    return store[tos--];
}

class BugFixStack : public Stack {
    public:
    void push(int x) {
        if (tos < 5) {
            Stack::push(x);
        }
    }

    int pop() {
        if (tos <= 0) {
            cout << "Stack is empty" << endl;
        }
        else {
            return Stack::pop();
        }
        return 0;
    }
};

class BugFixComposition {
    public:
    Stack stack;
    BugFixComposition( Stack stack ) : stack( stack ) {}

    void push(int x) {
        if (stack.tos < 5) {
            stack.push(x);
        }
    }

    int pop() {
        if (stack.tos <= 0) {
            cout << "Stack is empty" << endl;
        }
        else {

            return stack.pop();
        }
        return 0;
    }

};

int main() {
    cout << "Stack" << endl;
    Stack stack;

    // Bug fix stack
    BugFixComposition bstack (stack);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Data " << stack.pop() << endl;
    cout << "Data " << stack.pop() << endl;
    cout << "Data " << stack.pop() << endl;
    cout << "Data " << stack.pop() << endl;
    


    return 0;
}

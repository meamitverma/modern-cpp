#include<iostream>
#include<vector>
using namespace std;

class Widget {
    public:
    void doWork1() & {                              //for lvalue & used
        cout<<"working on lvalue object"<<endl;
    }
    void doWork() && {                             //for rvalue && used
        cout <<"working on rvalue object"<<endl;
    }
};

class Widget_vec {
    public:
    using DataType = std::vector<double>;

    Widget_vec(){
        values = {1, 19, 2,30, 4,56};
    }

    DataType data() &{
        return values;
    }   

    DataType data() &&{
        return std::move(values);
    }

    private:
    // bad variable name
    DataType values;
};

void setValue(int val){}
void setValue(const int &val){} // nor its not l or r value
void setValue(int &val){} // lValue
void setValue(int &&val){} // rValue

int main() {

    // Widget widget;
    // widget1.doWork1();             //return lvalue
    // Widget().doWork();            //return rvalue


    // Phase II widget
    Widget_vec widget;
    cout << "Display data from lValue object" << endl;
    for (const auto &value : widget.data()) {
        cout << value << " " << endl;
    }
    
    cout << "Display data from rValue object" << endl;
    for (const auto &value : Widget_vec().data()) {
        cout << value << " " << endl;
    }

    return 0;
}
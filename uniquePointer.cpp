#include <iostream>
#include <utility>
#include <memory>

using namespace std;

struct MyInt {
    MyInt(int i): i_(i) {}
    ~MyInt() {
        cout << "Goodbye from " << i_ << '\n';
    }

    int i_;
};

int main() {
    unique_ptr<MyInt> uniquePtr1{new MyInt(1998)};
    cout << uniquePtr1.get() << '\n';

    unique_ptr<MyInt> uniquePtr2{move(uniquePtr1)};
    cout << "uP1: " << uniquePtr1.get() << '\n';
    cout << "uP2: " << uniquePtr2.get() << '\n';
    {
        unique_ptr<MyInt> localPtr{new MyInt(2011)};
    }

    uniquePtr2.reset(new MyInt(2011));
    MyInt* myInt = uniquePtr2.release();
    cout << "Delete pointer myInt\n";
    cout << "uP2: " << uniquePtr2.get() << '\n';
    cout << "myInt: " << myInt -> i_ << '\n';
    delete myInt;

    unique_ptr<MyInt> uniquePtr3{new MyInt(2017)};
    unique_ptr<MyInt> uniquePtr4{new MyInt(2022)};
    cout << "uP3: " << uniquePtr3.get() << '\n';
    cout << "uP4: " << uniquePtr4.get() << '\n';

    swap(uniquePtr3, uniquePtr4);
    cout << "uP3: " << uniquePtr3.get() << '\n';
    cout << "uP4: " << uniquePtr4.get() << '\n';

    return 0;
}

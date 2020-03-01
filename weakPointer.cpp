#include <iostream>
#include <memory>

using std::cout;

class MyInt {
public:
    MyInt(int i): i_(i) {}
    int get() const { return i_; }
private:
    int i_;
};

int main() {
    // auto sharedPtr = std::make_shared<int>(2011);
    // std::weak_ptr<int> weakPtr(sharedPtr);
    //
    // cout << weakPtr.use_count() << '\n';
    // cout << sharedPtr.use_count() << '\n';
    //
    // cout << weakPtr.expired() << '\n';
    // if (std::shared_ptr<int> sharedPtr1= weakPtr.lock()) {
    //     cout << *sharedPtr << '\n';
    // } else {
    //     cout << "Don't get it!\n";
    // }
    //
    // weakPtr.reset();
    //
    // if (std::shared_ptr<int> sharedPtr1 = weakPtr.lock()) {
    //     cout << *sharedPtr1 << '\n';
    // } else {
    //     cout << "Don't get it!\n";
    // }

    cout << std::boolalpha;

    std::weak_ptr<MyInt> weakPtr;
    cout << "weakPtr.use_count(): " << weakPtr.use_count() << '\n';
    cout << "weakPtr.expired(): " << weakPtr.expired() << '\n';

    cout << '\n';

    std::shared_ptr<MyInt> sharedPtr(new MyInt(2011));
    cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << '\n';

    weakPtr = sharedPtr;
    cout << "weakPtr.use_count(): " << weakPtr.use_count() << '\n';
    cout << "weakPtr.expired(): " << weakPtr.expired() << '\n';

    // std::weak_ptr<MyInt> weakPtr1(sharedPtr);
    // cout << '\n';

    cout << "sharedPtr -> get(): " << sharedPtr -> get() << '\n';
    // cout << "weakPtr -> get(): " << weakPtr -> get() << '\n';

    if (std::shared_ptr<MyInt> sharedPtr1 = weakPtr.lock()) {
        cout << "sharedPtr -> get(): " << sharedPtr -> get() << '\n';
    } else {
        cout << "Don't get the resource!\n";
    }

    // swap
    std::shared_ptr<MyInt> sharedPtr2(new MyInt(2));
    std::shared_ptr<MyInt> sharedPtr3(new MyInt(3));
    std::weak_ptr<MyInt> weakPtr2(sharedPtr2);
    std::weak_ptr<MyInt> weakPtr3(sharedPtr3);

    if (std::shared_ptr<MyInt> sharedFromWeak2 = weakPtr2.lock()) {
        cout << "sharedFromWeak2 -> get(): " << sharedFromWeak2 -> get() << '\n';
    } else {
        cout << "Na-huh\n";
    }
    cout << '\n';

    weakPtr2.swap(weakPtr3);
    if (std::shared_ptr<MyInt> sharedFromWeak2 = weakPtr2.lock()) {
        cout << "sharedFromWeak2 -> get(): " << sharedFromWeak2 -> get() << '\n';
    } else {
        cout << "Na-huh\n";
    }
    cout << '\n';
    if (std::shared_ptr<MyInt> sharedFromWeak3 = weakPtr3.lock()) {
        cout << "sharedFromWeak3 -> get(): " << sharedFromWeak3 -> get() << '\n';
    } else {
        cout << "Na-huh\n";
    }
    cout << '\n';

    std::swap(weakPtr2, weakPtr3);
    if (std::shared_ptr<MyInt> sharedFromWeak2 = weakPtr2.lock()) {
        cout << "sharedFromWeak2 -> get(): " << sharedFromWeak2 -> get() << '\n';
    } else {
        cout << "Na-huh\n";
    }
    if (std::shared_ptr<MyInt> sharedFromWeak3 = weakPtr3.lock()) {
        cout << "sharedFromWeak3 -> get(): " << sharedFromWeak3 -> get() << '\n';
    } else {
        cout << "Na-huh\n";
    }

    cout << '\n';


    return 0;
}

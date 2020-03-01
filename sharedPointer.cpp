#include <iostream>
#include <memory>

using std::cout;

class MyInt {
public:
    MyInt(int v): val(v) {
        cout << (void*)this << " Hello: " << val << '\n';
    }
    ~MyInt() {
        cout << (void*)this << " Goodbye: " << val << '\n';
    }
private:
    int val;
};

int main() {
    auto sharePtr = std::make_shared<MyInt>(1998);
    cout << "sharePtr.use_count():" << sharePtr.use_count() << '\n';

    {
        std::shared_ptr<MyInt> locSharePtr(sharePtr);
        cout << "sharePtr.use_count():" << locSharePtr.use_count() << '\n';
    }
    cout << "sharePtr.use_count():" << sharePtr.use_count() << '\n';

    std::shared_ptr<MyInt> globalSharePtr = sharePtr;
    cout << "sharePtr.use_count():" << sharePtr.use_count() << '\n';
    cout << "globalSharePtr.use_count():" << globalSharePtr.use_count() << '\n';

    globalSharePtr.reset();
    cout << "globalPtr.use_count():" << globalSharePtr.use_count() << '\n';
    cout << "sharePtr.use_count():" << sharePtr.use_count() << '\n';
    sharePtr = std::shared_ptr<MyInt>(new MyInt(2011));
    cout << "sharePtr.use_count():" << sharePtr.use_count() << '\n';

    return 0;
}

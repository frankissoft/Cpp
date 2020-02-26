#include <iostream>
#include <utility>
#include <vector>

using std::cout;

template <typename T>
inline void swap(T& a, T& b) {
    T temp(std::move(a));
    a = std::move(b);
    b = std::move(temp);
}

template <typename T>
inline void swap2(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

struct MyData {
    std::vector<int> myData;

    MyData() :myData({1, 2, 3, 4, 5}) {}

    MyData(const MyData& m) :myData(m.myData) {
        std::cout << "copy constructor" << std::endl;
    }

    MyData& operator=(const MyData& m) {
        myData = m.myData;
        std::cout << "copy assignment operator" << std::endl;
        return *this;
    }
};

int main() {
    int myInt1 = 5;
    int myInt2 = 10;
    cout << "(myInt1, myInt2): (" << myInt1 << ", " << myInt2 << ")\n";
    swap(myInt1, myInt2);
    cout << "(myInt1, myInt2): (" << myInt1 << ", " << myInt2 << ")\n";

    std::cout << '\n';
    MyData a, b;
    swap(a, b);
    std::swap(a, b);
    std::cout << '\n';
    swap2(a, b);
    std::cout << '\n';

    return 0;
}

#include <iostream>
#include <utility>
#include <string>
#include <initializer_list>
#include <vector>

using std::cout;
using std::initializer_list;

struct MyData{
    MyData(int, double, char){};
};

template <typename T, typename... Args>
T createT(Args&&... args) {
    return T(std::forward<Args>(args)... );
}


int main() {
    int a = createT<int>();
    int b = createT<int>(1);

    std::string s = createT<std::string>("Only for testing.");
    MyData myData2 = createT<MyData>(1, 3.19, 'a');

    typedef std::vector<int> IntVec;

    IntVec intVec = createT<IntVec>(initializer_list<int>({1, 2, 3, 4, 5}));
    for (auto x : intVec) {
        cout << x << ", ";
    }
    cout << '\n';
}

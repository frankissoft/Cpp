#include <iostream>
#include <type_traits>
using namespace std;

int main() {
    cout << boolalpha;
    cout << is_const<int>::value << '\n';
    cout << is_const <const int>::value << '\n';
    cout << is_const<add_const<int>::type>::value << '\n';

    typedef add_const<int>::type myConstInt;
    cout << is_const<myConstInt>::value << '\n';

    typedef const int myConstInt2;
    cout << is_same<myConstInt, myConstInt2>::value << '\n';

    cout << is_same<int, remove_const<add_const<int>::type>::type>::value << '\n';
    cout << is_same<const int, add_const<int>::type>::value << '\n';
}

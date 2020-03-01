#include <iostream>
#include <string>
#include <tuple>
#include <utility>

using namespace std;

int main() {

    int first = 1;
    int second = 2;
    int third = 3;
    int fourth = 4;

    cout << first << " " << second << " "
        << third << " " << fourth << '\n';

    auto tup = tie(first, second, third, fourth)
        = make_tuple(101, 102, 103, 104);

    cout << first << " " << second << " "
        << third << " " << fourth << '\n';

    cout << get<0>(tup) << " " << get<1>(tup) << " "
        << get<2>(tup) << " " << get<3>(tup) << '\n';

    first = 201;
    get<1>(tup) = 202;

    cout << first << " " << second << " "
        << third << " " << fourth << '\n';

    cout << get<0>(tup) << " " << get<1>(tup) << " "
        << get<2>(tup) << " " << get<3>(tup) << '\n';

    int a, b;
    // tie(ignore, a, ignore, b) = tup;
    tie(ignore, ignore, ignore, b) = tup;

    cout << a << " " << b << '\n';
    return 0;
}

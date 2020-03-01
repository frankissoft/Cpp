#include <iostream>
#include <vector>
#include <tuple>
#include <utility>

using std::cout;

int main() {
    cout << std::boolalpha << std::endl;

    std::tuple<std::string, int, float> tup1("first", 3, 4.17f);
    auto tup2 = std::make_tuple("second", 4, 1.1);

    cout << "tup1: " << std::get<0>(tup1) << ", " << std::get<1>(tup1) << ", " << std::get<2>(tup1) << '\n';
    cout << "tup2: " << std::get<0>(tup2) << ", " << std::get<1>(tup2) << ", " << std::get<2>(tup2) << '\n';

    cout << "tup1 < tup2: " << (tup1 < tup2) << '\n';

    std::get<0>(tup2) = "Second";

    cout << "tup1: " << std::get<0>(tup1) << ", " << std::get<1>(tup1) << ", " << std::get<2>(tup1) << '\n';
    cout << "tup2: " << std::get<0>(tup2) << ", " << std::get<1>(tup2) << ", " << std::get<2>(tup2) << '\n';

    cout << "tup1 < tup2: " << (tup1 < tup2) << '\n';

    return 0;
}

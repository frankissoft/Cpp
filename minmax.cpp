#include <iostream>
#include <algorithm>

using std::cout;

int main() {
    cout << "std::min(2010, 2014): " << std::min(2010, 2014) << '\n';
    cout << "std::min(-10, -5, [](...) {...}): ";
    cout << std::min(-10, -5, [](int a, int b) {
        return std::abs(a) < abs(b);
    }) << '\n';


    std::pair<int, int> pairInt = std::minmax(2011, 2014);
    auto pairSeq = std::minmax({3, 1, 2011, 2014, -5});
    auto pairAbs = std::minmax({3, 1, 2011, 2014, -5}, [](int a, int b) {
        return std::abs(a) < std::abs(b);
    });

    cout << "(pairInt.first, pairInt.second): (" << pairInt.first << ", " << pairInt.second << ")\n";
    cout << "(pairSeq.first, pairSeq.second): (" << pairSeq.first << ", " << pairSeq.second << ")\n";
    cout << "(pairAbs.first, pairAbs.second): (" << pairAbs.first << ", " << pairAbs.second << ")\n";
    return 0;
}

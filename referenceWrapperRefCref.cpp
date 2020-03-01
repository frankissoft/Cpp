#include <iostream>
#include <functional>
#include <string>
#include <tuple>
#include <utility>

using std::cout;

void invokeMe(const std::string& s) {
    cout << s << ": const \n";
}

template <typename T>
void doubleMe(T t) {
    t *= 2;
}

int main() {
    cout << '\n';
    std::string s{ "string" };

    invokeMe(std::cref(s));
    cout << '\n';

    int i = 1;
    cout << "i: " << i << '\n';

    doubleMe(i);
    cout << "doubleMe(i): " << i << '\n';

    doubleMe(std::ref(i));
    cout << "doubleMe(std::ref(i)): " << i << "\n\n";

    int a{ 2011 };
    auto tup = std::make_pair(a, std::ref(a));
    cout << "(tup.first, tup.second): (" << tup.first << ", " << tup.second << ")\n";
    a = 2014;
    cout << "(tup.first, tup.second): (" << tup.first << ", " << tup.second << ")\n";

    cout << '\n';
    return 0;
}

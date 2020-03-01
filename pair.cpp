#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main() {
    pair<const char*, double> charDoub("str", 3.14);
    pair<const char*, double> charDoub2 = make_pair("str", 3.14);
    auto charDoub3 = make_pair("str", 3.14);

    std::string myString = "This is not a String...";
    auto strDouble = std::make_pair(myString, 3.14);

    cout << "charDoub: (" << charDoub.first << ", " << charDoub.second << ")\n";
    charDoub.first = "Str";
    get<1>(charDoub) = 4.14;
    cout << "charDoub: (" << charDoub.first << ", " << charDoub.second << "'\n";

    cout << "strDouble: (" << strDouble.first << ", " << strDouble.second << ")\n";
    if (charDoub2 == charDoub3) {
        cout << "charDoub2 == charDoub3\n";
    }
    if (charDoub2 > charDoub3) {
        cout << "charDoub2 > charDoub3\n";
    }

    return 0;
}

#include <iostream>
#include <functional>

using namespace std::placeholders;

using std::bind;
using std::function;

double divMe(double a, double b) { return a / b; }

int main() {
    function < double(double, double) > myDiv1 = bind(divMe, _1, _2);
    function < double(double) > myDiv2 = bind(divMe, 2000, _1);
    function < double(double) > myDiv3 = bind(divMe, _1, 10);
    std::cout << '\n';
    std::cout << (divMe(2000, 10) == myDiv1(2000, 10) == myDiv2(10) == myDiv3(2000));
    std::cout << '\n';
    std::cout << "divMe: " << divMe(2000, 10) << '\n';
    std::cout << "myDiv1: " << myDiv1(2000, 10) << '\n';
    std::cout << "myDiv2: " << myDiv2(10) << '\n';
    std::cout << "myDiv3: " << myDiv3(2000) << '\n';
    if (divMe(2000, 10) == myDiv1(2000, 10) == myDiv2(10) == myDiv3(2000)) {
        std::cout << "yeah!\n";
    } else {
        std::cout << "nah\n";
    }
    return 0;
}

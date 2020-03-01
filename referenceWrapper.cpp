#include <iostream>
#include <functional>

void foo() {
    std::cout << "Invoked" << '\n';
}

int main() {
    typedef void callableUnit();
    std::reference_wrapper<callableUnit> refWrap(foo);

    refWrap();
    return 0;
}

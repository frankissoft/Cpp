#include <iostream>
#include <type_traits>

using std::cout;

int main() {
    cout << std::boolalpha;
    cout << "is_void: " << std::is_void<void>::value << '\n';
    cout << "is_integral: " << std::is_integral<short>::value << '\n';
    cout << "is_floating_point: " << std::is_floating_point<double>::value << '\n';
    cout << "is_array: " << std::is_array<int []>::value << '\n';
    cout << "is_pointer: " << std::is_pointer<int*>::value << '\n';
    cout << "is_reference: " << std::is_reference<int&>::value << '\n';

    struct A {
        int a;
        int f(int) { return 2011; }
    };

    cout << "is_member_object_pointer: " << std::is_member_object_pointer<int A::*>::value << '\n';
    cout << "is_member_funcion_pointer: " << std::is_member_function_pointer<int (A::*)(int)>::value << '\n';

    enum E {
        e = 1,
    };

    cout << "is_enum: " << std::is_enum<E>::value << '\n';

    union U {
        int u;
    };

    cout << "is_union: " << std::is_union<U>::value << '\n';

    cout << "is_class: " << std::is_class<std::string>::value << '\n';
    cout << "is_function: " << std::is_function<int * (double)>::value << '\n';
    cout << "is_lvalue_reference: " << std::is_lvalue_reference<int&>::value << '\n';
    cout << "is_rvalue_reference: " << std::is_rvalue_reference<int&&>::value << '\n';

    return 0;
}

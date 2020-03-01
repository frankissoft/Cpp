#include <iostream>
#include <memory>

using namespace std;

class MyStruct {
public:
    MyStruct(): val(count){
        cout << static_cast<void*>(this) << " Hello: " << val << '\n';
        MyStruct::count++;
    }
    ~MyStruct() {
        MyStruct::count--;
        cout << static_cast<void*>(this) << " Goodbye: " << val << '\n';
    }
private:
    int val;
    static int count;
};

int MyStruct::count = 0;

int main() {
    unique_ptr<MyStruct[]> myuniqueArray{ new MyStruct[5] };

    {
        unique_ptr<MyStruct[]> myUniqueArray{ new MyStruct[1]};
        MyStruct myStruct;
        myUniqueArray[0] = myStruct;
    }    

    {
        unique_ptr<MyStruct[]> myUniqueArray { new MyStruct[1]};
        MyStruct myStruct;
        myStruct = myUniqueArray[0];
    }

    unique_ptr<MyStruct> upms = make_unique<MyStruct>();
    return 0;
}

#include <iostream>
#include <type_traits>

class Foo
{
private:
    int tempVal;
public:
//    Foo();
    Foo(int inVal) = delete;
//    Foo(int inVal, int inVal2){}
    Foo(int inVal = 0, int inVal2 = 0){}
//    Foo(const Foo&){}
//    Foo(Foo&&){}
};

bool ifDeclaredCTORDefault();
bool ifDeclaredCTOR1();
bool ifDeclaredCTOR2();
bool ifDeclaredCTORCopy();
bool ifDeclaredCTORMove();

int main()
{
    std::cout << std::boolalpha << " If compiler generates ctor default: " << std::is_trivially_constructible<Foo>::value << "\n";
    std::cout << std::boolalpha << " If compiler generates ctor copy: " << std::is_trivially_constructible<Foo, const Foo&>::value << "\n";
    std::cout << std::boolalpha << " If compiler generates ctor move: " << std::is_trivially_constructible<Foo, Foo&&>::value << "\n";
    std::cout << std::boolalpha << " If compiler generates ctor 1: " << std::is_trivially_constructible<Foo, int>::value << "\n";
    std::cout << std::boolalpha << " If compiler generates ctor 2: " << std::is_trivially_constructible<Foo, int, int>::value << "\n";
    std::cout << std::boolalpha << " If declared ctor default : " << ifDeclaredCTORDefault() << "\n";
    std::cout << std::boolalpha << " If created by user ctor copy : " << ifDeclaredCTORCopy() << "\n";
    std::cout << std::boolalpha << " If created by user ctor move : " << ifDeclaredCTORMove() << "\n";
    std::cout << std::boolalpha << " If created by user ctor 1 : " << ifDeclaredCTOR1() << "\n";
    std::cout << std::boolalpha << " If created by user ctor 2 : " << ifDeclaredCTOR2() << "\n";
    return 0;
}

bool ifDeclaredCTORDefault()
{
    return std::is_constructible<Foo>::value && !std::is_trivially_constructible<Foo>::value;
}

bool ifDeclaredCTOR1()
{
    return std::is_constructible<Foo, int>::value && !std::is_trivially_constructible<Foo, int>::value;
}

bool ifDeclaredCTOR2()
{
    return std::is_constructible<Foo, int, int>::value && !std::is_trivially_constructible<Foo, int, int>::value;
}

bool ifDeclaredCTORCopy()
{
    return std::is_constructible<Foo, const Foo&>::value && !std::is_trivially_constructible<Foo, const Foo&>::value;
}

bool ifDeclaredCTORMove()
{
    return std::is_constructible<Foo, Foo&&>::value && !std::is_trivially_constructible<Foo, Foo&&>::value;
}

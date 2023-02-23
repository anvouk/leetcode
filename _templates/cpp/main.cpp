#include <iostream>
#include <vector>

using namespace std;

template <typename Arg, typename... Args>
void print(Arg &&arg, Args &&...args)
{
    std::cout << std::forward<Arg>(arg);
    ((std::cout << ' ' << std::forward<Args>(args)), ...);
    std::cout << '\n';
}

int main()
{
    print("Hello", "Andy");
    return 0;
}

#include <iostream>

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum(n - 1);
}

int main()
{
    int num;
    std::cout << "enter n: ";
    std::cin >> num;
    int result = sum(num);
    std::cout << result << std::endl;
    return 0;
}
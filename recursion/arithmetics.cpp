// Write a recursive method that uses only addition, subtraction, and comparison to multiply two numbers.
#include <iostream>
#include <string>
using namespace std;

int multiply(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;

    if (b == 1)
        return a;

    return multiply(a, b - 1) + a;
}
int main()
{
    cout << multiply(3, 100);
}
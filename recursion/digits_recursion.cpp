#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void printDigits(int n)
{
    unordered_map<int, string> map;
    map[0] = "zero";
    map[1] = "one";
    map[2] = "two";
    map[3] = "three";
    map[4] = "four";
    map[5] = "five";
    map[6] = "six";
    map[7] = "seven";
    map[8] = "eight";
    map[9] = "nine";

    if (n == 0)
        return;

    printDigits(n / 10);
    cout << map[n % 10] << " ";
}
int main()
{
    printDigits(423433);
}
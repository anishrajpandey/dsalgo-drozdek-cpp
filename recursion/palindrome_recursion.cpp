#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string text, int left, int right)
{

    if (left >= right)
        return true;
    if (text[left] != text[right])
        return false;

    return isPalindrome(text, left + 1, right - 1);
};
int main()
{
    string text = "racecar";
    int left = 0;
    int right = text.length() - 1;

    cout << isPalindrome(text, left, right);
}
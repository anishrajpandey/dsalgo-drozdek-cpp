// Write a recursive method that for a positive integer returns a string with commas in the appropriate places, for example, putCommas(1234567) returns the string “1,234,567.
#include <string>
#include <iostream>
using namespace std;

string putCommas(string number)
{
    int length = number.length();
    if (length == 0)
        return "";
    if (length <= 3)
    {
        return number;
    }

    string subStr = number.substr(length - 3, 3);

    string remainder = number.substr(0, length - 3);

    return putCommas(remainder) + "," + subStr;
}

// 12345 678

int main()
{
    string num;

    cin >> num;

    string result = putCommas(num);
    cout << endl
         << "the resullt is " << result;
}
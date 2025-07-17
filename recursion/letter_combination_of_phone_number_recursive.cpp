#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(string &digits, int index, string &current, vector<string> &result, const vector<string> &mapping)
{
    // Base Case: if we've formed a full combination
    if (index == digits.length())
    {
        result.push_back(current);
        return;
    }

    // Get the letters mapped to the current digit
    string letters = mapping[digits[index] - '0'];

    // Explore all possible letters for the current digit
    for (char letter : letters)
    {
        current.push_back(letter);                              // choose
        backtrack(digits, index + 1, current, result, mapping); // explore
        current.pop_back();                                     // un-choose (backtrack)
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};

    vector<string> mapping = {"", "", "abc", "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string current = "";

    backtrack(digits, 0, current, result, mapping);

    return result;
}

int main()
{
    string digits = "23";
    vector<string> combinations = letterCombinations(digits);
    for (string s : combinations)
    {
        cout << s << " ";
    }
    return 0;
}

#include <vector>

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        std::vector<int> indexArray(temperatures.size(), 0);
        std::vector<int> indexStack;

        for (int i = 0; i < temperatures.size(); i++)
        {
            // While stack is not empty and current temperature is higher than the temperature at the top of the stack
            while (!indexStack.empty() && temperatures[i] > temperatures[indexStack.back()])
            {
                // Calculate days difference for the temperature at the top of the stack
                indexArray[indexStack.back()] = i - indexStack.back();
                indexStack.pop_back();
            }
            indexStack.push_back(i);
        }

        return indexArray;
    }
};
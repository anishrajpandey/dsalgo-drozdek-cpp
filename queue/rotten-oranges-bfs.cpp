#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<vector<int>> q;
        int minute = 0, fresh = 0;

        // Step 1: Count fresh oranges and enqueue rotten ones
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        // Directions: right, left, down, up
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // Step 2: BFS layer by layer (minute by minute)
        while (!q.empty() && fresh > 0)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int currX = q.front()[0];
                int currY = q.front()[1];
                q.pop();

                for (int j = 0; j < 4; j++)
                {
                    int newX = currX + dx[j];
                    int newY = currY + dy[j];

                    if (newX >= 0 && newX < grid.size() &&
                        newY >= 0 && newY < grid[0].size() &&
                        grid[newX][newY] == 1)
                    {

                        grid[newX][newY] = 2;
                        fresh--;
                        q.push({newX, newY});
                    }
                }
            }
            minute++;
        }

        return (fresh == 0) ? minute : -1;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    int result = solution.orangesRotting(grid);
    cout << "Minutes to rot all oranges: " << result << endl;

    return 0;
}

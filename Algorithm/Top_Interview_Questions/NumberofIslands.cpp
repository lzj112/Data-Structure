/*
给定一个“1”(陆地)和“0”(水域)的二维网格地图，计算岛屿的数量。
岛屿被水环绕，通过水平或垂直连接相邻的陆地而形成。你可以假设网格的四个边都被水包围着。
Example 1:
Input:
11110
11010
11000
00000
Output: 1

Example 2:
Input:
11000
11000
00100
00011
Output: 3
*/
#include <vector>
using namespace std;

class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    numIslandsDFS(grid, visited, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
    void numIslandsDFS(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y)
    {
        if (x < 0 || x >= grid.size())
            return;
        if (y < 0 || y >= grid[0].size())
            return;
        if (grid[x][y] != '1' || visited[x][y])
            return;
        visited[x][y] = true;
        numIslandsDFS(grid, visited, x - 1, y);
        numIslandsDFS(grid, visited, x + 1, y);
        numIslandsDFS(grid, visited, x, y - 1);
        numIslandsDFS(grid, visited, x, y + 1);
    }
};
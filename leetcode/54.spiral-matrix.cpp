/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void recursion(vector<vector<int>> &matrix, int i, int j, vector<bool> &Visited, int direction, int left, vector<int> &res)
    {
        if (left == 0)
        {
            return;
        }

        res.push_back(matrix[i][j]);

        int m = matrix.size();
        int n = matrix[0].size();

        Visited[i * n + j] = true;

        if (direction == 0)
        {
            if ((j + 1 < n) && !Visited[i * n + j + 1])
            {
                recursion(matrix, i, j + 1, Visited, 0, left - 1, res);
            }
            else
            {
                recursion(matrix, i + 1, j, Visited, 1, left - 1, res);
            }
        }
        else if (direction == 1)
        {
            if ((i + 1) < m && !Visited[(i + 1) * n + j])
            {
                recursion(matrix, i + 1, j, Visited, 1, left - 1, res);
            }
            else
            {
                recursion(matrix, i, j - 1, Visited, 2, left - 1, res);
            }
        }
        else if (direction == 2)
        {
            if ((j - 1) > -1 && !Visited[(i)*n + j - 1])
            {
                recursion(matrix, i, j - 1, Visited, 2, left - 1, res);
            }
            else
            {
                recursion(matrix, i - 1, j, Visited, 3, left - 1, res);
            }
        }
        else if (direction == 3)
        {
            if ((i - 1) > -1 && !Visited[(i - 1) * n + j])
            {
                recursion(matrix, i - 1, j, Visited, 3, left - 1, res);
            }
            else
            {
                recursion(matrix, i, j + 1, Visited, 0, left - 1, res);
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> Visited(m * n, false);
        vector<int> res;
        recursion(matrix, 0, 0, Visited, 0, m * n, res);
        return res;
    }
};
// @lc code=end

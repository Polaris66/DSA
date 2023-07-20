/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool Visited[9];

        for (int i = 0; i < 9; i++)
        {
            memset(Visited, false, sizeof(Visited));
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int current = board[i][j] - '1';
                    cout << current << endl;
                    if (!Visited[current])
                    {
                        Visited[current] = true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++)
        {
            memset(Visited, false, sizeof(Visited));
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    int current = board[j][i] - '1';
                    cout << current << endl;

                    if (!Visited[current])
                    {
                        Visited[current] = true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        // Boxes
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                memset(Visited, false, sizeof(Visited));
                for (int x = i * 3; x < (i + 1) * 3; x++)
                {
                    for (int y = j * 3; y < (j + 1) * 3; y++)
                    {
                        if (board[x][y] != '.')
                        {
                            int current = board[x][y] - '1';
                            cout << x << " " << y << " " << current << endl;

                            if (!Visited[current])
                            {
                                Visited[current] = true;
                            }
                            else
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

void recursion(vector<vector<char>> board, int index, vector<vector<char>> &res)
{
    if (index == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                res[i][j] = board[i][j];
            }
        }
        return;
    }
    int row = index / 9;
    int column = index % 9;

    if (board[row][column] != '.')
    {
        recursion(board, index + 1, res);
        return;
    }
    vector<bool> Visited(9, false);
    for (int i = 0; i < 9; i++)
    {
        if (board[i][column] != '.')
        {
            Visited[board[i][column] - '1'] = true;
        }
        if (board[row][i] != '.')
        {
            Visited[board[row][i] - '1'] = true;
        }
        if (board[3 * (row / 3) + i / 3][3 * (column / 3) + i % 3] != '.')
        {
            Visited[board[3 * (row / 3) + i / 3][3 * (column / 3) + i % 3] - '1'] = true;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (!Visited[i])
        {
            board[row][column] = i + '1';
            recursion(board, index + 1, res);
        }
    }
}

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        recursion(board, 0, board);
    }
};
// @lc code=end

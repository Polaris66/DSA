#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> recursion(vector<vector<int>> res, vector<int> prevRow, int n, int maxN)
{
    if (n == maxN)
    {
        return res;
    }
    vector<int> current;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            current.push_back(1);
        }
        else
        {
            current.push_back(prevRow[j] + prevRow[j + 1]);
            j++;
        }
    }
    res.push_back(current);
    return recursion(res, current, n + 1, maxN);
}
vector<vector<int>> recursive(int numRows)
{
    if (numRows == 1)
    {
        return {{1}};
    }
    return recursion({{1}}, {1}, 2, numRows + 1);
}

vector<int> generateRow(int row)
{
    vector<int> Row;
    Row.push_back(1);
    int curr = 1;
    for (int col = 1; col < row; col++)
    {
        curr *= (row - col);
        curr /= col;
        Row.push_back(curr);
    }
    return Row;
}

vector<vector<int>> generate(int n)
{
    vector<vector<int>> res;
    for (int i = 1; i <= n; i++)
    {
        res.push_back(generateRow(i));
    }
    return res;
}
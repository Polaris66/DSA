#include <bits/stdc++.h>
using namespace std;
void setZero(vector<vector<int>> &matrix, int n, int m, int x, int y)
{
    for (int j = 0; j < m; j++)
    {
        matrix[x][j] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        matrix[i][y] = 0;
    }
}

// T.C- O(n3) S.C- O(n2)
vector<vector<int>> bruteForce(vector<vector<int>> &matrix, int n, int m)
{
    vector<vector<int>> Matrix(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                setZero(Matrix, n, m, i, j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Matrix[i][j] == -1)
            {
                Matrix[i][j] = matrix[i][j];
            }
        }
    }

    return Matrix;
}

// Store rows and columns to be zeroed and zero them
// T.C - O(m*n), S.C - O(m+n)
vector<vector<int>> better(vector<vector<int>> &matrix, int m, int n)
{
    vector<int> rows(m, 1);
    vector<int> cols(n, 1);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rows[i] == 0 || cols[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

// T.C - O(m*n), S.C - O(1)
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int m, int n)
{
    int col0 = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}
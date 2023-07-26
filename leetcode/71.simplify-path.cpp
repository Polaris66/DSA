/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string simplifyPath(string s)
    {
        stack<string> S;
        int n = s.size();
        int i = 0;
        string temp = "";
        while (i < n)
        {
            temp = "";
            while (i < n && s[i] == '/')
            {
                i++;
            }

            if (s[i] == '.')
            {
                int dotCount = 0;
                while (i < n && s[i] == '.')
                {
                    dotCount++;
                    i++;
                }
                if (dotCount == 2 && ((i == n) || s[i] == '/'))
                {
                    if (!S.empty())
                    {
                        S.pop();
                    }
                }
                else if (dotCount == 1 && ((i == n) || s[i] == '/'))
                {
                    dotCount = 0;
                }
                else
                {
                    while (dotCount--)
                    {
                        temp += '.';
                    }
                }
            }

            while ((i < n) && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || (s[i] == '_')) || s[i] == '.')
            {
                temp += s[i];
                i++;
            }

            if (temp.size())
            {
                S.push(temp);
            }
        }

        vector<string> V;
        string res = "";

        while (!S.empty())
        {
            string temp = S.top();
            V.push_back(temp);
            S.pop();
        }

        reverse(V.begin(), V.end());

        for (string temp : V)
        {
            res += '/';
            res += temp;
        }
        if (!res.size())
            return "/";
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=636 lang=cpp
 *
 * [636] Exclusive Time of Functions
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> res(n, 0);
        stack<pair<int, int>> st;
        for (int i = 0; i < logs.size(); i++)
        {
            string s = logs[i];
            if (s[2] == 's')
            {
                int func = s[0] - '0';
                int time = s[8] - '0';
                if (!st.empty())
                {
                    pair<int, int> prev = st.top();
                    res[prev.first] += time - prev.second;
                }
                cout << func << " " << time << endl;
                st.push(make_pair(func, time));
            }
            else
            {
                int func = s[0] - '0';
                int time = s[6] - '0';
                cout << func << " " << time << endl;
                pair<int, int> prev = st.top();
                st.pop();
                res[prev.first] += time - prev.second + 1;
                if (!st.empty())
                {
                    prev = st.top();
                    st.pop();
                    st.push(make_pair(prev.first, time + 1));
                }
            }
        }
        return res;
    }
};
// @lc code=end

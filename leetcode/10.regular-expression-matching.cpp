/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool recursion(string &s, string &p, int i, int j){
        
        if((i<0) && (j<0)) return true;

        if((i>=0) && (j<0)) return false;

        if((i<0) && (j>=0)){
            for(int k = j; k >= 0; k--){
                if(p[k]!='*'){
                    return false;
                }
                else{
                    k--;
                }
            }
            return true;
        }

        // Recursive Case
        if (p[j] == '.' || s[i] == p[j])
        {
            return recursion(s, p, i - 1, j - 1);
        }
        if(p[j]=='*'){
            bool res = false;
            if(p[j-1]=='.' || p[j-1]==s[i]){
                res = res || recursion(s, p, i-1, j);
            }
            res = res || recursion(s, p, i, j-2);
            return res;
        }
        return false;
    }

    bool isMatch(string s, string p) {
        return recursion(s,p,s.size()-1,p.size()-1);
    }
};
// @lc code=end


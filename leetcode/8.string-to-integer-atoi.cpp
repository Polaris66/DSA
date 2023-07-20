/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        int started = 0;
        int res = 0;
        for(int i = 0; i < n; i++){
            char c = s[i];
            cout<<c<<endl;
            if((c =='+') && !started){
                sign = 1;
                started = 1;
            }
            else if((c=='-') && !started){
                sign = -1;
                started = 1;
            }
            else{
                if((c >= '0') && (c <= '9')){
                    if(!started){
                        started = 1;
                    }

                    if(res > INT_MAX / 10){
                        return INT_MAX;
                    }
                    if(res < INT_MIN / 10){
                        return INT_MIN;
                    }
                    res *= 10;

                    if(sign==1){
                        if(res >= INT_MAX - (c-'0')){
                            return INT_MAX;
                        }
                        res += (c - '0');
                    }
                    else{
                        if(res <= INT_MIN + (c-'0')){
                            return INT_MIN;
                        }
                        res -= (c - '0');
                    }
                }
                else {
                    if(c!=' '){
                        break;
                    }
                    if(started){
                        break;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end


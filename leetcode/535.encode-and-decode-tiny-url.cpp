/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<string, string> Decode;
    int count = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string tinyUrl = "http://tinyurl.com/" + to_string(count);
        Decode[tinyUrl] = longUrl;
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return Decode[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

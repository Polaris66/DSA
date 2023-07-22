/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<string, pair<int, int>> mp;
    int id;
    vector<TreeNode *> res;
    string postOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "0";
        }

        string l = postOrder(root->left);
        string r = postOrder(root->right);

        string cur = l + ',' + to_string(root->val) + ',' + r;

        if (mp.find(cur) == mp.end())
        {
            mp[cur] = make_pair(id++, 1);
        }
        else
        {
            mp[cur].second++;
            if (mp[cur].second == 2)
            {
                res.push_back(root);
            }
        }

        return to_string(mp[cur].first);
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        id = 1;
        postOrder(root);
        return res;
    }
};
// @lc code=end

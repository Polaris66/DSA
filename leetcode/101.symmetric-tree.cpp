/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
class Solution
{
public:
    bool solve(TreeNode *a, TreeNode *b)
    {
        if (a == nullptr && b == nullptr)
        {
            return true;
        }

        if (a == nullptr)
        {
            return false;
        }

        if (b == nullptr)
        {
            return false;
        }

        if (a->val != b->val)
        {
            return false;
        }

        return solve(a->left, b->right) && solve(a->right, b->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return solve(root->left, root->right);
    }
};
// @lc code=end

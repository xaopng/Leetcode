/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
class Solution {
public:
    TreeNode* helper(TreeNode* root) {
        if (root -> left == root -> right) return root;
        if (!root -> left) {
            return helper(root -> right);
        } 
            TreeNode* leftEnd = helper(root -> left);
            leftEnd -> right = root -> right;
            root -> right = root -> left;
            root -> left = nullptr;
            return root -> right ? helper(root -> right) : leftEnd; 
        
    }
    void flatten(TreeNode* root) {
        if (!root) return;
        helper(root);
    }
};
// @lc code=end


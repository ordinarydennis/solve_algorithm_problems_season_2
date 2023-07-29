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

    int val = 0;

    bool traversal(TreeNode* root)
    {
        if (nullptr == root)
        {
            return true;
        }

        if (false == traversal(root->left))
        {
            return false;
        }

        if (val != root->val)
        {
            return false;
        }

        return traversal(root->right);
    }


public:
    bool isUnivalTree(TreeNode* root) {

        val = root->val;

        return traversal(root);
    }
};
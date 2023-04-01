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

    bool traversal(TreeNode* root, int k, int count)
    {
        if (2 == count)
        {
            return (root->val == k);
        }

        if (root->val < k)
        {
            traversal(root->right, k, count + 1)
        }
        else
        {
            traversal(root->left, k, count + 1)
        }


    }

public:
    bool findTarget(TreeNode* root, int k) {

        return traversal(root, k, 1);

    }
};
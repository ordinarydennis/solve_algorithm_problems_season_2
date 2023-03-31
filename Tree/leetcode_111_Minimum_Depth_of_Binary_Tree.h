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

    int traversal(TreeNode* root)
    {
        int l = 10000;

        if (root->left)
        {
            l = traversal(root->left);
        }

        int r = 10000;

        if (root->right)
        {
            r = traversal(root->right);
        }

        if (!root->left && !root->right)
        {
            return 1;
        }

        return std::min(l, r) + 1;
    }


public:
    int minDepth(TreeNode* root) {

        if (nullptr == root)
        {
            return 0;
        }

        return traversal(root);

    }
};

[         3, 
      9,     20, 
null, null, 15, 7]
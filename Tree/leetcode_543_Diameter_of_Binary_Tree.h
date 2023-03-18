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

    int max = 0;

    int treversal(TreeNode* root)
    {
        if (nullptr == root)
        {
            return 0;
        }

        int l = treversal(root->left);
        int r = treversal(root->right);

        max = std::max(max, l + r);

        return std::max(r, l) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {

        treversal(root);

        return max;
    }
};

//https://leetcode.com/problems/diameter-of-binary-tree/solutions/573591/c-5-lines-o-n-solution/
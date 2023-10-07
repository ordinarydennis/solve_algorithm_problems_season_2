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

    int sum = 0;

    void traversal(TreeNode* root)
    {
        if (nullptr == root)
        {
            return;
        }

        traversal(root->right);

        root->val += sum;

        sum = root->val;

        traversal(root->left);

        return;
    }


public:
    TreeNode* convertBST(TreeNode* root) {

        traversal(root);

        return root;
    }
};
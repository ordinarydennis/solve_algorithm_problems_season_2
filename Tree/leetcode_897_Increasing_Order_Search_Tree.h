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


    void traversal(TreeNode* root, TreeNode* out)
    {
        if (nullptr == root)
        {
            return;
        }

        traversal(root->left, out);

        out = root;

        traversal(root->right, out);
    }


public:
    TreeNode* increasingBST(TreeNode* root) {

        TreeNode* out = new TreeNode();

        traversal(root, out);

        return out;
    }
};
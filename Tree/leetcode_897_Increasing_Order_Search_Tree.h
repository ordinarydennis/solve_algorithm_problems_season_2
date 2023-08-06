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

    void traversal(TreeNode* root, TreeNode*& newNode)
    {
        if (nullptr == root)
        {
            return;
        }

        traversal(root->left, newNode);

        newNode->right = new TreeNode(root->val);
 
        newNode = newNode->right;

        traversal(root->right, newNode);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {

        TreeNode* newNode = new TreeNode();

        TreeNode* it = newNode;

        traversal(root, it);

        return newNode->right;
    }
};
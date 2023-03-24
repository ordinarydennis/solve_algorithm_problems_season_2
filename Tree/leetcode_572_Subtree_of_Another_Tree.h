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

    bool traversal(TreeNode* root, TreeNode* subRoot, bool ischecking)
    {
		traversal(root->left, subRoot);
		traversal(root->right, subRoot);
    }



public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        return traversal(root, subRoot);

    }
};
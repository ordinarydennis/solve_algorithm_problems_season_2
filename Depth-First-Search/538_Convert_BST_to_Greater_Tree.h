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


    int dfs(TreeNode* proot, TreeNode* root, bool r)
    {
        if (nullptr == root)
        {
            return 0;
        }

        root->val += dfs(root, root->right);

        root->val += dfs(root, root->left) + proot->val;
        
        return root->val;
    }

public:
    TreeNode* convertBST(TreeNode* root) {

        dfs(root);

        return root;
    }
};
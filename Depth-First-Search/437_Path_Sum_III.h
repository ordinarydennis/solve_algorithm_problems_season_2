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

    void dfs(TreeNode* root, int sum, int targetSum, int& ret)
    {
        if (nullptr == root)
        {
            return ;
        }

        if (targetSum == root->val + sum)
        {
            ret++;
        }

        if (targetSum <= root->val + sum)
        {
			dfs(root->left, root->val, targetSum, ret);
			dfs(root->right, root->val, targetSum, ret);
        }

        else
        {
            dfs(root->left, root->val + sum, targetSum, ret);
            dfs(root->right, root->val + sum, targetSum, ret);
        }
    }

public:
    int pathSum(TreeNode* root, int targetSum) {

        int ret = 0;

        dfs(root, 0, targetSum, ret);

        return ret;
    }
};
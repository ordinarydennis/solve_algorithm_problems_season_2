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

    int count = 0;

    void dfs(TreeNode* root, long long sum, int targetSum)
    {
        if (nullptr == root)
        {
            return;
        }

        if (root->val + sum == targetSum)
        {
            count++;
        }

        dfs(root->left, root->val + sum, targetSum);
        dfs(root->right, root->val + sum, targetSum);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {

        dfs(root, 0, targetSum);
        
        if (root)
        {
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        
        return count;
    }
};

//https://leetcode.com/problems/path-sum-iii/solutions/683906/c-dfs-clean-solution-t-89-m-80/
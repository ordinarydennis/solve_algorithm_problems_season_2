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

    void traversal(TreeNode* root, int targetSum, int sum)
    {
        if (nullptr == root)
        {
            return ;
        }

        sum += root->val;

        if (targetSum == sum)
        {
            count++;
        }

        traversal(root->left, targetSum, sum);
        traversal(root->right, targetSum, sum);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {

        traversal(root, targetSum, 0);

        if (root)
        {
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        
        return count;
    }
};
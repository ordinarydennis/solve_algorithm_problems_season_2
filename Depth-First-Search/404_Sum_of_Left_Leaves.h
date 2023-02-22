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

    bool dfs(TreeNode* node, bool isLeft)
    {
		if (nullptr == node)
		{
            return true;
        }

        if (dfs(node->left, true))
        {
            if(isLeft)
                sum += node->val;
        }

        dfs(node->right, false);

        return false;
    }


public:
    int sumOfLeftLeaves(TreeNode* root) {

        dfs(root, false);

        return sum;
	}
};
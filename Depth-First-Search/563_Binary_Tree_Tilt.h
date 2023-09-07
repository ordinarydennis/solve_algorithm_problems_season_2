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

	int dfs(TreeNode* root)
	{
		if (nullptr == root)
		{
			return 0;
		}

		return root->val + dfs(root->left) + dfs(root->right);
	}

public:
    int findTilt(TreeNode* root) {
		
		if (nullptr == root)
		{
			return 0;
		}

		sum = abs(dfs(root->left) - dfs(root->right));

		findTilt(root->left);
		findTilt(root->right);

		return sum;
    }
};
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

	int treveralRight(TreeNode* root)
	{
		if (nullptr == root)
		{
			return -100000;
		}

		if (nullptr == root->right)
		{
			return root->val;
		}

		return treveralRight(root->right);
	}

	int treveralLeft(TreeNode* root)
	{
		if (nullptr == root)
		{
			return 100000;
		}

		if (nullptr == root->left)
		{
			return root->val;
		}

		return treveralRight(root->left);
	}

public:
	int getMinimumDifference(TreeNode* root) {

		int left = treveralRight(root->left);
		int right = treveralLeft(root->right);

		return std::min(right - root->val, root->val - left);
	}
};

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

	int min = INT_MAX;

	int minValue(TreeNode* root)
	{
		if (nullptr == root->left && nullptr == root->right)
		{
			return root->val;
		}

		int l = INT_MAX;
		int r = INT_MAX;
	
		if (root->left)
		{
			l = root->val - minValue(root->left);
		}

		if (root->right)
		{
			r = minValue(root->right) - root->val;
		}

		min = std::min(
				min,
				std::min(l, r)
			);

		return nullptr != root->right ? root->right->val : root->val;
	}

public:
	int minDiffInBST(TreeNode* root) {

		minValue(root);

		return min;

	}
};
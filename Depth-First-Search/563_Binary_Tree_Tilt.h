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

	int traversal(TreeNode* root, int& sum)
	{
		if (nullptr == root)
		{
			return 0;
		}

		int l = traversal(root->left, sum);
		int r = traversal(root->right, sum);

		sum += abs(l - r);

		return root->val + l + r;
	}


public:
	int findTilt(TreeNode* root) {

		int sum = 0;

		traversal(root, sum);

		return sum;

	}
};
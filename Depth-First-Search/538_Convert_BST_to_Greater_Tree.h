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

	int mSum = 0;


	void dfs(TreeNode* root)
	{
		if (nullptr == root)
		{
			return;
		}

		dfs(root->right);

		root->val += mSum;

		mSum = root->val;

		dfs(root->left);
	}

public:
	TreeNode* convertBST(TreeNode* root) {

		dfs(root);

		return root;
	}
};

//https://leetcode.com/problems/convert-bst-to-greater-tree/solutions/100610/c-solution-beats-100/
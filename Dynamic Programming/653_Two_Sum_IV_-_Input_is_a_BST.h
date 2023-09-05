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

	std::vector<int> v;

	void dfs(TreeNode* root, std::vector<int>& v)
	{
		if (nullptr == root)
			return;

		dfs(root->left, v);

		v.push_back(root->val);

		dfs(root->right, v);
	}

public:
	bool findTarget(TreeNode* root, int k) {

		dfs(root, v);

		int l = 0;
		int r = v.size() - 1;

		while (l < r)
		{
			if (k == v[l] + v[r])
			{
				return true;
			}

			if (k < v[l] + v[r])
			{
				r--;
			}
			else
			{
				l++;
			}
		}

		return false;
	}
};
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


	int dfs(TreeNode* root, std::unordered_map<int, int>& m)
	{
		if (nullptr == root)
		{
			return 0;
		}

		int sum = root->val + dfs(root->left, m) + dfs(root->right, m);

		m[sum]++;

		return sum;
	}

public:
	vector<int> findFrequentTreeSum(TreeNode* root) {

		std::unordered_map<int, int> m;

		dfs(root, m);

		int max = 0;

		vector<int> ret;

		for (const auto& [n, c] : m)
		{
			if (c < max)
				continue;

			if (max < c)
			{
				max = c;
				ret.clear();
			}

			ret.push_back(n);
		}

		return ret;
	}
};
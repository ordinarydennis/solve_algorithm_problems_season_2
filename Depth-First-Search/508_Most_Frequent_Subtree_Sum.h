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

	unordered_map<int, int> m;
	int maxCount = 0;

	int dfs(TreeNode* root)
	{
		if (nullptr == root)
		{
			return 0;
		}

		int sum = root->val + dfs(root->left) + dfs(root->right);

		m[sum]++;

		maxCount = std::max(maxCount, m[sum]);

		return sum;
	}

public:
	vector<int> findFrequentTreeSum(TreeNode* root) {

		dfs(root);

		std::vector<int> ret;

		for (const auto& [s, c] : m)
		{
			if (c == maxCount)
			{
				ret.push_back(s);
			}
		}

		return ret;
	}
};

//https://leetcode.com/problems/most-frequent-subtree-sum/solutions/98675/java-c-python-dfs-find-subtree-sum/
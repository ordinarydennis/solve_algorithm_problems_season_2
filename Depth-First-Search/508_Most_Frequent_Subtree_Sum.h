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

	int traversal(TreeNode* root, std::unordered_map<int, int>& memo, int& max)
	{
		if (nullptr == root) return 0;

		int sum = traversal(root->left, memo, max) + traversal(root->right, memo, max) + root->val;

		max = std::max(max, ++memo[sum]);

		return sum;
	}


public:
	vector<int> findFrequentTreeSum(TreeNode* root) {

		std::unordered_map<int, int> memo;

		int max = 0;

		traversal(root, memo, max);

		std::vector<int> ret;

		std::for_each(memo.begin(), memo.end(), [&ret, &max](const auto& pair) {
			if (max == pair.second)
			{
				ret.push_back(pair.first);
			}
			}
		);

		return ret;
	}
};
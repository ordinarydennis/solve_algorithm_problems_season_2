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

	void traversal(TreeNode* root, int d, std::map<int, int>& memo)
	{
		if (nullptr == root)
			return;

		auto it = memo.find(d);

		memo[d] = (memo.end() == it) ? root->val : std::max(root->val, it->second);

		traversal(root->left, d + 1, memo);
		traversal(root->right, d + 1, memo);
	}


public:
	vector<int> largestValues(TreeNode* root) {

		std::map<int, int> memo;

		traversal(root, 0, memo);

		std::vector<int> ret;
		ret.reserve(memo.size());

		std::for_each(memo.begin(), memo.end(), [&ret](const auto& pair) { 
			ret.push_back(pair.second); 
			}
		);

		return ret;
	}
};
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

	string dfs(TreeNode* root, unordered_map<string, vector<TreeNode*>>& memo)
	{
		if (nullptr == root)
		{
			return "";
		}

		string l = dfs(root->left, memo);
		string r = dfs(root->right, memo);

		string result = "(" + l + to_string(root->val) + r + ")";

		memo[result].push_back(root);

		return result;
	}

public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

		vector<TreeNode*> ret;

		unordered_map<string, vector<TreeNode*>> memo;

		dfs(root, memo);

		for (const auto& [_, list] : memo)
		{
			if (list.size() >= 2)
			{
				ret.push_back(list[0]);
			}
		}

		return ret;
	}
};
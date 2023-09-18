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

	std::unordered_map<string, vector<TreeNode*>> m;

	string dfs(TreeNode* root)
	{
		if (nullptr == root)
			return "";

		string ret = "(" + dfs(root->left) + to_string(root->val) + dfs(root->right) + ")";

		m[ret].push_back(root);

		return ret;
	}


public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

		dfs(root);

		vector<TreeNode*> ret;

		for (const auto& [k, list] : m)
		{
			if (list.size() > 1)
				ret.push_back(list[0]);				
		}

		return ret;
	}
};


https://leetcode.com/problems/find-duplicate-subtrees/solutions/106055/c-java-clean-code-with-explanation/
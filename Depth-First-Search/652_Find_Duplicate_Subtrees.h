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

	string dfs(TreeNode* root, unordered_map<string, std::vector<TreeNode*>>& treeMap)
	{
		if (nullptr == root)
		{
			return "";
		}

		string ls = dfs(root->left, treeMap);
		string rs = dfs(root->right, treeMap);

		auto result = "(" + ls + to_string(root->val) + rs + ")";

		treeMap[result].push_back(root);

		return result;
	}

public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

		unordered_map<string, std::vector<TreeNode*>> treeMap;

		dfs(root, treeMap);

		std::vector<TreeNode*> ret;

		for (auto it : treeMap)
		{
			if (2 <= it.second.size())
				ret.push_back(it.second[0]);
		}

		return ret;
	}
};
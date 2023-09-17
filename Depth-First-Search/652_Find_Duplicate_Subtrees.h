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

	vector<vector<TreeNode*>> mR;

	vector<TreeNode*> dfs(TreeNode* root)
	{
		if (nullptr == root)
		{
			return {};
		}

		const auto& l = dfs(root->left);
		const auto& r = dfs(root->right);

		int li = 0;
		int ri = 0;

		vector<TreeNode*> vList;

		while (li < l.size() && ri < r.size())
		{
			if (l[li]->val == r[ri]->val)
			{
				vList.push_back(l[li]);
			}
			
			li++;
			ri++;
		}

		if (vList.size())
		{
			mR.push_back(std::move(vList));
		}

		vector<TreeNode*> ret;

		ret = std::move(l);

		ret.push_back(root);

		for (auto* e : r)
		{
			ret.push_back(e);
		}
	
		return ret;
	}


public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

		dfs(root);

		return mR;
		
	}
};
class Solution {

	TreeNode* dfs(TreeNode* root, int curDepth, int val, int depth, int left)
	{
		if (curDepth == depth)
		{
			if (nullptr == root)
			{
				return new TreeNode(val, nullptr, nullptr);
			}
			else
			{
				TreeNode* l = nullptr;
				TreeNode* r = nullptr;
				if (1 == left)
				{
					l = root;
					return new TreeNode(val, l, r);
				}
				else if (2 == left)
				{
					r = root;
					return new TreeNode(val, l, r);
				}
			}
		}

		if (root)
		{
			root->left = dfs(root->left, curDepth + 1, val, depth, 1);
			root->right = dfs(root->right, curDepth + 1, val, depth, 2);
		}

		return root;
	}

public:
	TreeNode* addOneRow(TreeNode* root, int val, int depth) {

		dfs(root, 1, val, depth, 0);

		return root;

	}
};
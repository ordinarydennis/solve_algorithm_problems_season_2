class Solution {

	TreeNode* dfs(TreeNode* root, int curDepth, int val, int depth, int left)
	{
		if (curDepth == depth)
		{
			TreeNode* l = nullptr;
			TreeNode* r = nullptr;

			if (nullptr == root)
			{
				return new TreeNode(val, l, r);
			}
			else
			{
				auto** t = (1 == left) ? &l : &r;
				*t = root;
				return new TreeNode(val, l, r);
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

		root = dfs(root, 1, val, depth, 1);

		return root;

	}
};
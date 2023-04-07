class Solution {
public:
	int res = INT_MAX, pre = -1;

	int minDiffInBST(TreeNode* root)
	{
		if (nullptr != root->left)
		{
			minDiffInBST(root->left);
		}

		if (0 <= pre)
		{
			res = std::min(res, root->val - pre);
		}

		pre = root->val;

		if (nullptr != root->right)
		{
			minDiffInBST(root->right);
		}

		return res;
	}
};

//https://leetcode.com/problems/minimum-distance-between-bst-nodes/solutions/114834/c-java-python-inorder-traversal-o-n-time-recursion/?orderBy=most_votes
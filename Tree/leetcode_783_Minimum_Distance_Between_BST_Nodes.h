class Solution {
public:
	int res = INT_MAX, pre = -1;

	int minDiffInBST(TreeNode* root)
	{
		if (root->left != NULL) 
			minDiffInBST(root->left);

		if (pre >= 0) 
			res = min(res, root->val - pre);

		pre = root->val;

		if (root->right != NULL) 
			minDiffInBST(root->right);

		return res;
	}
};

//https://leetcode.com/problems/minimum-distance-between-bst-nodes/solutions/114834/c-java-python-inorder-traversal-o-n-time-recursion/?orderBy=most_votes
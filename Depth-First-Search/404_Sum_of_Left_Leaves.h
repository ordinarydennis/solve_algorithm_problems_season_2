class Solution {

	int dfs(TreeNode* root, bool isLeft) {

		if (!root) 
			return 0;

		if (!root->left && !root->right)
			return isLeft ? root->val : 0;

		return dfs(root->left, true) + dfs(root->right, false);
	}


public:
	int sumOfLeftLeaves(TreeNode* root) {

		return dfs(root, false);

	}
};

//https://leetcode.com/problems/sum-of-left-leaves/solutions/1558055/c-python-recursive-iterative-dfs-bfs-morris-traversal-o-1-w-explanation-beats-100/?orderBy=most_votes

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

	int lastVal = -1;
	int min = INT_MAX;

	void traveral(TreeNode* root)
	{
		if (nullptr == root)
		{
			return;
		}

		traveral(root->left);

		if (0 <= lastVal)
		{
			min = std::min(min, root->val - lastVal);
		}

		lastVal = root->val;

		traveral(root->right);
	}


public:
	int getMinimumDifference(TreeNode* root) {

		traveral(root);

		return min;

	}
};

//In-order traversal of BST yields sorted sequence. 
//https://leetcode.com/problems/minimum-absolute-difference-in-bst/solutions/99938/c-o-n-o-h/?orderBy=most_votes

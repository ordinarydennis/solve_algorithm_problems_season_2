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

	TreeNode* traversal(TreeNode* root, int val)
	{
		if (nullptr == root)
		{
			return nullptr;
		}

		if (root->val == val)
		{
			return root;
		}

		return (root->val < val) ? traversal(root->right, val) : traversal(root->left, val);

	}


public:
	TreeNode* searchBST(TreeNode* root, int val) {

		return traversal(root, val);

	}
};
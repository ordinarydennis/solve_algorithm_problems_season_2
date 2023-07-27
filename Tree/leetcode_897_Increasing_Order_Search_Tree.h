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

	void traversal(TreeNode* root, TreeNode*& out)
	{
		if (nullptr == root)
		{
			return;
		}

		traversal(root->left, out);

		out->right = new TreeNode(root->val);

		out = out->right;

		traversal(root->right, out);
	}


public:
	TreeNode* increasingBST(TreeNode* root) {

		TreeNode* out = new TreeNode();

		TreeNode* it = out;

		traversal(root, it);

		return out->right;
	}

};


//https://leetcode.com/problems/increasing-order-search-tree/solutions/958108/c-inorder-traversal-o-n-easy-to-understand/

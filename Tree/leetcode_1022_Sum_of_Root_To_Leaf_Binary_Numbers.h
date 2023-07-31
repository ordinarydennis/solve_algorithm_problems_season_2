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

	int mSum = 0;

	void traversal(TreeNode* root, int sum)
	{
		if (nullptr == root)
		{
			return;
		}

		if (nullptr == root->left && nullptr == root->right)
		{
			mSum += (sum << 1) + root->val;
			return;
		}

		traversal(root->left, (sum << 1) + root->val);

		traversal(root->right, (sum << 1) + root->val);
	}


public:
	int sumRootToLeaf(TreeNode* root) {

		traversal(root, 0);

		return mSum;
	}
};

[    1, 
  0,    1, 
0, 1,  0, 1
]

  1
1
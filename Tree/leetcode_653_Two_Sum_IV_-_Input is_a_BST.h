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

	std::vector<int> list;

	void traversal(TreeNode* root, std::vector<int>& list)
	{
		if (nullptr == root)
		{
			return;
		}

		traversal(root->left, list);

		list.push_back(root->val);

		traversal(root->right, list);

	}

public:
	bool findTarget(TreeNode* root, int k) {

		std::vector<int> list;

		traversal(root, list);

		int l = 0;
		int r = static_cast<int>(list.size()) - 1;

		while (l < r)
		{
			if (k == list[l] + list[r])
			{
				return true;
			}
			if (k < list[l] + list[r])
			{
				r--;
			}
			else
			{
				l++;
			}
		}

		return false;
	}
};
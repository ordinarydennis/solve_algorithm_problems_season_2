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

    int treversal(TreeNode* root)
    {
		if (nullptr == root)
		{
			return 0;
		}

        int max = std::max(
            treversal(root->left),
            treversal(root->right)
        );
        return max + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {

        return treversal(root->left) + treversal(root->right);

    }
};

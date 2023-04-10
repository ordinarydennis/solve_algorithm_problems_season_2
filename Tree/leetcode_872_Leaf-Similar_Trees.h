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




    void traversal(TreeNode* root1, std::vector<int>& leafs)
    {
        if (!root1->left && !root1->right)
        {
            leafs.push_back(root1->val);
        }

        if (root1->left)
        {
            traversal(root1->left, leafs);
        }

		if (root1->right)
		{
			traversal(root1->right, leafs);
		}
    }


public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

		std::vector<int> leaf1;
		std::vector<int> leaf2;

        traversal(root1, leaf1);
        traversal(root2, leaf2);

        return leaf1 == leaf2;

    }
};
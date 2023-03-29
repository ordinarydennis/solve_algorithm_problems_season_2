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

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

		if (nullptr == root1 && nullptr == root2)
		{
			return nullptr;
		}

		TreeNode* merged = new TreeNode();
		merged->val += nullptr != root1 ? root1->val : 0;
		merged->val += nullptr != root2 ? root2->val : 0;

		merged->left = mergeTrees(
			root1 != nullptr ? root1->left : nullptr,
			root2 != nullptr ? root2->left : nullptr
		);

		merged->right = mergeTrees(
			root1 != nullptr ? root1->right : nullptr,
			root2 != nullptr ? root2->right : nullptr
		);

        return merged;
    }
};

//https://leetcode.com/problems/merge-two-binary-trees/solutions/104308/java-c-clean-code-unique-node-shared-node-5-liner/
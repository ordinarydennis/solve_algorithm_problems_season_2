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
	TreeNode* addOneRow(TreeNode* root, int val, int depth) {

		if (1 == depth)
		{
			auto* node = new TreeNode(val);
			node->left = root;
			return node;
		}

		std::queue<TreeNode*> q;
		q.push(root);

		while (q.size())
		{
			auto size = q.size();

			while (size--)
			{
				auto* node = q.front();

				q.pop();

				if (2 < depth)
				{
					if (node->left)
					{
						q.push(node->left);
					}
					if (node->right)
					{
						q.push(node->right);
					}
				}
				else
				{
					auto* leftNode = new TreeNode(val);
					auto* leftTemp = node->left;
					node->left = leftNode;
					leftNode->left = leftTemp;

					auto* rightNode = new TreeNode(val);
					auto* rightTemp = node->right;
					node->right = rightNode;
					rightNode->right = rightTemp;
				}
			}

			--depth;
		}

		return root;
	}
};
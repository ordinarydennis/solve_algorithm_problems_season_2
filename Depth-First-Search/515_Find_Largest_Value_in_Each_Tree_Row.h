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
	vector<int> largestValues(TreeNode* root) {

		if (nullptr == root)
		{
			return {};
		}

		std::queue<TreeNode*> q;

		vector<int> ret;

		q.push(root);

		while (q.size())
		{
			int s = static_cast<int>(q.size());

			int max = INT_MIN;

			for (int i = 0; i < s; i++)
			{
				const auto* node = q.front();

				max = std::max(max, node->val);

				q.pop();

				if (node->left)
				{
					q.push(node->left);
				}

				if (node->right)
				{
					q.push(node->right);
				}
			}

			ret.push_back(max);
		}

		return ret;
	}
};
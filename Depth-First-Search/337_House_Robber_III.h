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
	int rob(TreeNode* root) {

		if (nullptr == root)
		{
			return 0;
		}

		std::queue<TreeNode*> q;

		q.push(root);

		int count = 0;

		int sum[2] = { 0, 0 };

		while (q.size())
		{
			int s = q.size();
			for (int i = 0; i < s; i++)
			{
				auto* node = q.front();

				sum[count % 2] += node->val;

				if (node->left)
				{
					q.push(node->left);
				}
				if (node->right)
				{
					q.push(node->right);
				}

				q.pop();
			}
			
			count++;
		}
		
		return std::max(sum[0], sum[1]);
	}
};


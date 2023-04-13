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
    int findBottomLeftValue(TreeNode* root) {

		std::queue<TreeNode*> q;

        q.push(root);
        
		const TreeNode* node = nullptr;

        while (q.size())
        {
			node = q.front();

			q.pop();

			//need to push right node first because we need to find left node of last row.
			if (node->right)
			{
				q.push(node->right);
			}

			if (node->left)
			{
				q.push(node->left);
			}
        }
        
        return node->val;
    }
};

//https://leetcode.com/problems/find-bottom-left-tree-value/solutions/98779/right-to-left-bfs-python-java/
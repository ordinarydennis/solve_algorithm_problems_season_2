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

    TreeNode* dfs(TreeNode* root, int val, int depth, bool isLeft)
    {
        if (depth < 0)
        {
            return nullptr;
        }

        if (0 == depth)
        {
            auto* newNode = new TreeNode(val);

            if (root)
            {
				if (isLeft)
				{
					newNode->left = root->left;
				}
				else
				{
                    newNode->right = root->right;
				}
            }

            return newNode;
        }

       root->left = dfs(root->left, val, depth - 1, true);
       root->right = dfs(root->right, val, depth - 1, false);

        return root;
    }


public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        return dfs(root, val, depth - 1, true);
    }
};
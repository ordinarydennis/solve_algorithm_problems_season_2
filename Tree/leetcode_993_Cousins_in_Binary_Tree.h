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


    int xd = 0;
    int xp = 0;
    int yd = 0;
    int yp = 0;


    void traversal(TreeNode* root, int p, int x, int y, int d)
    {
        if (nullptr == root)
        {
            return;
        }

        traversal(root->left, root->val, x, y, d + 1);

        if (x == root->val)
        {
            xd = d;
            xp = p;
        }

        if (y == root->val)
        {
            yd = d;
            yp = p;
        }

        traversal(root->right, root->val, x, y, d + 1);
    }


public:
    bool isCousins(TreeNode* root, int x, int y) {

        traversal(root, 0, x, y, 0);

        return (yp != xp && xd == yd);
    }
};
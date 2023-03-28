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

    void mergeTree(TreeNode* root1, TreeNode* root2, TreeNode* merged)
    {
        if (nullptr == root1 && nullptr == root2)
        {
            return;
        }

        merged = new TreeNode();
        merged->val += nullptr != root1 ? root1->val : 0;
        merged->val += nullptr != root2 ? root2->val : 0;

		mergeTree(
            root1 != nullptr ? root1->left : nullptr, 
            root2 != nullptr ? root2->left : nullptr, 
            merged->left
        );

		mergeTree(
            root1 != nullptr ? root1->right : nullptr, 
            root2 != nullptr ? root2->right : nullptr, 
            merged->right
        );
    }

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        TreeNode* merged = nullptr;

        mergeTree(root1, root2, merged);

        return merged;
    }
};


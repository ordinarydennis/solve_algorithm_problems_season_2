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

    std::unordered_map<int, int> um;

    int max = 0;

    void traversal(TreeNode* root)
    {
        if (nullptr == root)
        {
            return;
        }

        um[root->val]++;

        max = std::max(um[root->val], max);

        traversal(root->left);
        traversal(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {

        traversal(root);

        vector<int> ret;

        for (const auto [num, count] : um)
        {
            if (max == count)
            {
                ret.push_back(num);
            }
        }

        return ret;
    }
};


//solve it in following ways
//https://leetcode.com/problems/find-mode-in-binary-search-tree/solutions/98101/proper-o-1-space/?orderBy=most_votes
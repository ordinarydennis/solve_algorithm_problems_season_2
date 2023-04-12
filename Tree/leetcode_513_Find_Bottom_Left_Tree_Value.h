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

		std::queue<std::pair<TreeNode*, bool>> q;

        int ret = INT_MIN;

        if (root->left)
        {
            q.push({ root, false });
        }
        else
        {
			q.push({ root, true });
			ret = root->val;
        }
        
        while (q.size())
        {
            int size = q.size();

			for (int i = 0; i < size; i++)
            {
                auto pair = q.front();

                q.pop();
               
                if (pair.first->left)
                {
                    q.push({ pair.first->left , true });
                }

                if (pair.first->right)
                {
                    q.push({ pair.first->right, false });
                }
                
                if (pair.second)
                {
                    ret = std::max(ret, pair.first->val);
                }
                
            }
        }
        
        return ret;
    }
};
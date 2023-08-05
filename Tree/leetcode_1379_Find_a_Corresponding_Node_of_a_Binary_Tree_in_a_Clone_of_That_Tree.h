/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

    TreeNode* found = nullptr;

    void traversal(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if (nullptr == original)
        {
            return;
        }

        traversal(original->left, cloned->left, target);

        if (target == original)
        {
            found = cloned;
        }

        traversal(original->right, cloned->right, target);
    }


public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        traversal(original, cloned, target);

        return found;
    }
};

class Solution {

    TreeNode* ret = nullptr;

    void traversal(TreeNode* cloned, TreeNode* target)
    {
        if (nullptr == cloned)
        {
            return;
        }

        if (ret)
        {
            return;
        }

        traversal(cloned->left, target);

        if (target->val == cloned->val)
        {
            ret = cloned;
            return;
        }

        traversal(cloned->right, target);
    }


public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        traversal(cloned, target);

        return ret;

    }
};


//solution
//https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/solutions/538009/c-minimalizm/
class Solution {

public:
	TreeNode* getTargetCopy(TreeNode* orig, TreeNode* clone, TreeNode* targ) {

		return orig == nullptr ? nullptr :
			orig == targ ? clone :
			getTargetCopy(orig->left, clone->left, targ) ? : getTargetCopy(orig->right, clone->right, targ);

	}
};
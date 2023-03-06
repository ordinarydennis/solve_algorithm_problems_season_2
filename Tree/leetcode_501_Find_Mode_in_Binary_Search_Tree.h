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


//difference of pre order, in order, post order
//pre order can't calculate right node.
//post order can't calculate left node.

public class Solution {

	public int[] findMode(TreeNode root) {
		
		//why is it two pass?

		inorder(root);
		modes = new int[modeCount];
		modeCount = 0;
		currCount = 0;
		inorder(root);
		return modes;
	}

	private int currVal;
	private int currCount = 0;
	private int maxCount = 0;
	private int modeCount = 0;

	private int[] modes;

	private void handleValue(int val) {
		if (val != currVal) {
			currVal = val;
			currCount = 0;
		}
		currCount++;
		if (currCount > maxCount) {
			maxCount = currCount;
			modeCount = 1;
		}
		else if (currCount == maxCount) {
			if (modes != null)
				modes[modeCount] = currVal;
			modeCount++;
		}
	}

	private void inorder(TreeNode root) {
		if (root == null) return;
		inorder(root.left);
		handleValue(root.val);
		inorder(root.right);
	}
}
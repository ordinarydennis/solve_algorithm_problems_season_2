//Time Limit Exceeded
class Solution {
public:
	int rob(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int val = 0;

		if (root->left != nullptr) {
			val += rob(root->left->left) + rob(root->left->right);
		}

		if (root->right != nullptr) {
			val += rob(root->right->left) + rob(root->right->right);
		}

		return std::max(val + root->val, rob(root->left) + rob(root->right));
	}

};

class Solution {
public:
	int rob(TreeNode* root) {
		map<TreeNode*, int> map;
		return robSub(root, map);
	}

private:
	int robSub(TreeNode* root, map<TreeNode*, int>& map)
	{
		if (root == nullptr)
			return 0;

		if (map.count(root))
			return map[root];

		int val = 0;

		if (root->left != nullptr)
		{
			val += robSub(root->left->left, map) + robSub(root->left->right, map);
		}

		if (root->right != nullptr) {
			val += robSub(root->right->left, map) + robSub(root->right->right, map);
		}

		val = std::max(val + root->val, robSub(root->left, map) + robSub(root->right, map));
		map.emplace(root, val);

		return val;
	}

};
//https://leetcode.com/problems/house-robber-iii/solutions/79330/step-by-step-tackling-of-the-problem/
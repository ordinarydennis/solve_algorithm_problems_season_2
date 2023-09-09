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

	std::vector<int> v;

	void dfs(TreeNode* root, std::vector<int>& v)
	{
		if (nullptr == root)
			return;

		dfs(root->left, v);

		v.push_back(root->val);

		dfs(root->right, v);
	}

public:
	bool findTarget(TreeNode* root, int k) {

		dfs(root, v);

		int l = 0;
		int r = v.size() - 1;

		while (l < r)
		{
			if (k == v[l] + v[r])
			{
				return true;
			}

			if (k < v[l] + v[r])
			{
				r--;
			}
			else
			{
				l++;
			}
		}

		return false;
	}
};

class BSTIterator {
	stack<TreeNode*> s;
	TreeNode* node;
	bool forward;
	int cur;
public:
	BSTIterator(TreeNode* root, bool forward) : node(root), forward(forward) 
	{ 
		(*this)++; 
	};

	int operator*() { return cur; }


	void operator++(int) {
		while (node || !s.empty()) {
			if (node) {
				s.push(node);
				node = forward ? node->left : node->right;
			}
			else {
				node = s.top();
				s.pop();
				cur = node->val;
				node = forward ? node->right : node->left;
				break;
			}
		}
	}
};

class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		if (!root) 
			return false;

		BSTIterator l(root, true);

		BSTIterator r(root, false);

		while (*l < *r) {
			if (*l + *r == k) 
				return true;
			else if 
				(*l + *r < k) 
				l++;
			else 
				r++;
		}
		return false;
	}
};

//BST Iterator
//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/solutions/106063/c-clean-code-o-n-time-o-lg-n-space-binarytree-iterator/




class BSTIterator {
	stack<TreeNode*> s;
	TreeNode* node;
	bool forward;
	int cur;
public:
	BSTIterator(TreeNode* root, bool forward) : node(root), forward(forward) { (*this)++; };
	int operator*() { return cur; }
	void operator++(int) {
		while (node || !s.empty()) {
			if (node) {
				s.push(node);
				node = forward ? node->left : node->right;
			}
			else {
				node = s.top();
				s.pop();
				cur = node->val;
				node = forward ? node->right : node->left;
				break;
			}
		}
	}
};
class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		if (!root) return false;
		BSTIterator l(root, true);
		BSTIterator r(root, false);
		while (*l < *r) {
			if (*l + *r == k) return true;
			else if (*l + *r < k) l++;
			else r++;
		}
		return false;
	}
};

class BSTIterator
{
	TreeNode* node;
	int cur;
	std::stack<TreeNode*> s;
	bool forward = false;

public:
	BSTIterator(TreeNode* root, bool f)
		:node(root), forward(f)
	{
		(*this)++;
	}
	int operator* ()
	{
		return cur;
	}
	void operator++(int)
	{
		while (node || s.size()) {
			if (node)
			{
				s.push(node);
				node = forward ? node->left : node->right;
			}
			else
			{
				auto* t = s.top();
				s.pop();
				cur = t->val;
				node = forward ? t->right : t->left;
				break;
			}
		}
	}
};
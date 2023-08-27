/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
*/

class Solution {

	void dfs(Node* root, vector<int>& ret)
	{
		if (nullptr == root)
		{
			return;
		}

		ret.push_back(root->val);


		for (Node* n : root->children)
		{
			dfs(n, ret);
		}
	}

public:
	vector<int> preorder(Node* root) {

		vector<int> ret;

		dfs(root, ret);

		return ret;
	}
};
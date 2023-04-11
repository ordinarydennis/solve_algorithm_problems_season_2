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

public:
	vector<vector<int>> levelOrder(Node* root) {

		vector<vector<int>> ret;

		std::queue<const Node*> q;

		q.push(root);

		while (q.size())
		{
			int size = q.size();

			vector<int> valList;

			for (int i = 0; i < size; i++)
			{
				auto* n = q.front();

				q.pop();

				if (nullptr == n)
				{
					break;
				}

				valList.push_back(n->val);

				for (const auto* node : n->children)
				{
					q.push(node);
				}
			}

			if (valList.size())
			{
				ret.push_back(std::move(valList));
			}
		}

		return ret;

	}
};
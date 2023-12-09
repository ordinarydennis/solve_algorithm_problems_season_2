/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/

class Solution {

	void search(Node* node, Node* destNode, unordered_set<Node*>& memo)
	{
		if (nullptr == node)
			return;

		for (Node* n : node->neighbors)
		{
			Node* newNode = new Node(n->val);
			destNode->neighbors.push_back(newNode);

			if (memo.count(n))
			{
				continue;
			}

			memo.insert(n);

			search(n, newNode, memo);

			memo.erase(n);
	
		}
	}


public:
	Node* cloneGraph(Node* node) {

		if (nullptr == node)
		{
			return nullptr;
		}

		unordered_set<Node*> memo;

		Node* retNode = new Node(node->val);

		memo.insert(node);

		search(node, retNode, memo);

		memo.erase(node);

		return retNode;

	}
};

//https://leetcode.com/problems/clone-graph/solutions/42313/c-bfs-dfs/
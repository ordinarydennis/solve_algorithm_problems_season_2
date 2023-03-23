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

    int traversalTree(Node* root)
    {
        if (nullptr == root)
        {
            return 0;
        }

        int max = 0;

        for (auto* node : root->children)
        {
            int depth = traversalTree(node);

            max = std::max(max, depth);
        }

        return max + 1;
    }


public:
    int maxDepth(Node* root) {

        return traversalTree(root);

    }
};
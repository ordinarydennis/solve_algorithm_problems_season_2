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

    vector<int> ret;

    void dfs(Node* root)
    {
        if (nullptr == root)
        {
            return;
        }

        if (root->children.empty())
        {
            ret.push_back(root->val);
            return;
        }

        for (auto* n : root->children)
        {
            dfs(n);
        }

        ret.push_back(root->val);
    }


public:
    vector<int> postorder(Node* root) {

        dfs(root);

        return ret;

    }
};
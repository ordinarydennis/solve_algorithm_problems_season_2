class Solution {


	int traversal(vector<int>& min, std::unordered_map<int, vector<int>>& g, std::unordered_set<int>& checker,  int node, int h)
	{
		if (checker.count(node))
		{
			return 0;
		}

		checker.insert(node);

		int retH = 0;

		for (int n : g[node])
		{
			int h2 = traversal(min, g, checker, n, h) + 1;
			std::max(retH, h2);
		}

		checker.erase(node);


		if (min.empty())
		{
			min.push_back(node);
		}
		else if (retH < min[0])
		{
			min = std::move(vector<int> { node } );
		}
		else if (retH == min[0])
		{
			min.push_back(node);
		}

		return retH;
	}

public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

		vector<int> min(n, INT_MAX);

		std::unordered_map<int, vector<int>> g;

		std::unordered_set<int> checker;

		for (const auto& edge : edges)
		{
			g[edge[0]].push_back(edge[1]);
			g[edge[1]].push_back(edge[0]);
		}

		for (int i = 0; i < n; i++)
		{
			traversal(min, g, checker, i, 0);
		}

		return min;
	}
};


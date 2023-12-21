class Solution {

	int traversal(unordered_map<int, vector<int>>& mat, int dest, int index)
	{
		if (dest == index) return 0;
	

		auto it = mat.find(index);

		if (mat.end() == it) return -1;

		if (it->second.empty())
		{
			return -1;
		}
		
		int ret = 0;

		for (int n : it->second)
		{
			int p = traversal(mat, dest, n);
			
			if (-1 == p)
			{
				continue;
			}

			ret = std::min(ret, p) + 1;
		}

		return ret;
	}

public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

		unordered_map<int, vector<int>> mat;

		for (const auto e : redEdges)
		{
			mat[e[0]].push_back(e[1]);
		}

		for (const auto e : blueEdges)
		{
			mat[e[0]].push_back(e[1]);
		}

		vector<int> ret;

		for (int i = 0; i < n; i++)
		{
			ret.push_back(
				traversal(mat, i, 0)
			);
		}

		return ret;
	}
};
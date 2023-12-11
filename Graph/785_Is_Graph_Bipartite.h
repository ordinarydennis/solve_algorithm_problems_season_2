class Solution {

	bool dfs(vector<vector<int>>& graph, int start, int index, int count)
	{
		if (graph.size() - 1 == count)
		{
			return true;
		}

		for (int i = 0; i < graph[index].size(); i++)
		{
			if (start == graph[index][i])
			{
				return true;
			}
			if (dfs(graph, start, graph[index][i], count + 1))
			{
				return true;
			}

		}

		return false;
	}


public:
	bool isBipartite(vector<vector<int>>& graph) {

		for (int a = 0; a < graph.size(); a++)
		{
			for (int b = 0; b < graph[a].size(); b++)
			{
				if (dfs(graph, a, graph[a][b], 0))
				{
					return false;
				}
			}
		}

		return true;

	}
};
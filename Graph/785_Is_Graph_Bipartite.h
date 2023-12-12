class Solution {

	bool dfs(vector<vector<int>>& graph, int index, vector<int>& colors, int color)
	{
		if (0 != colors[index])
		{
			return (colors[index] == color);
		}

		colors[index] = color;

		for (const auto& neighbor: graph[index])
		{
			if (false == dfs(graph, neighbor, colors, -color))
			{
				return false;
			}
		}

		return true;
	}


public:
	bool isBipartite(vector<vector<int>>& graph) {

		vector<int> colors(graph.size());

		for (int i = 0; i < graph.size(); i++)
		{
			if (colors[i] == 0 && false == dfs(graph, i, colors, 1))
				return false;
		}


		return true;
	}
};

//what is bipartite
//https://gmlwjd9405.github.io/2018/08/23/algorithm-bipartite-graph.html
//solution
//https://leetcode.com/problems/is-graph-bipartite/solutions/3540122/image-explanation-both-bfs-dfs-ways-c-java-python/
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


//https://leetcode.com/problems/shortest-path-with-alternating-colors/solutions/656384/c-bfs-with-explanation/
class Solution {
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		// constructing adjacency matrix
		vector<vector<pair<int, int>>> graph(n);
		for (auto edge : red_edges)
			graph[edge[0]].emplace_back(edge[1], 0); //red edges are denoted by 0 
		for (auto edge : blue_edges)
			graph[edge[0]].emplace_back(edge[1], 1); // blue edges are denoted by 1
		vector<int> dist(n, -1);

		queue<vector<int>> q;
		q.emplace(vector<int>{0, 0, -1});

		while (!q.empty()) {
			auto front = q.front();
			q.pop();
			dist[front[0]] = dist[front[0]] != -1 ? dist[front[0]] : front[1];

			for (auto& adj : graph[front[0]]) {
				//Push the node to the queue only if the next edge color is different from the pervious edge color and also if we are visiting the edge
				//for the first time.
				if (front[2] != adj.second && adj.first != -1) {
					q.emplace(vector<int>{adj.first, front[1] + 1, adj.second});
					//Update the value in the adjacency matrix to -1 to denote that the node has already been visited.
					adj.first = -1;
				}
			}
		}
		return dist;
	}
};
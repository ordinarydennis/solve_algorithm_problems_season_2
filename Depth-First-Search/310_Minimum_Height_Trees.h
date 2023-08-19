//dfs
class Solution {

	void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int& maxDepth, int depth) {

		visited[node] = true;
		
		maxDepth = max(maxDepth, depth);

		for (int neighbor : graph[node])
		{
			if (!visited[neighbor])
			{
				dfs(neighbor, graph, visited, maxDepth, depth + 1);
			}
		}
	}

public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		
		if (n == 1) {
			return { 0 };
		}

		vector<vector<int>> graph(n);

		for (const vector<int>& edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}

		vector<int> rootCandidates;

		int minDepth = n;

		for (int i = 0; i < n; ++i)
		{
			vector<bool> visited(n, false);

			int maxDepth = 0;

			dfs(i, graph, visited, maxDepth, 0);

			if (maxDepth < minDepth)
			{
				rootCandidates.clear();
				rootCandidates.push_back(i);
				minDepth = maxDepth;
			}
			else if (maxDepth == minDepth) {
				rootCandidates.push_back(i);
			}
		}

		return rootCandidates;
	}
};

//bfs
class Solution {

public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n == 1) {
			return { 0 };
		}

		vector<unordered_set<int>> graph(n);
		for (const vector<int>& edge : edges) {
			graph[edge[0]].insert(edge[1]);
			graph[edge[1]].insert(edge[0]);
		}

		vector<int> leaves;
		for (int i = 0; i < n; ++i) {
			if (graph[i].size() == 1) {
				leaves.push_back(i);
			}
		}

		while (n > 2) {
			n -= leaves.size();
			vector<int> newLeaves;
			for (int leaf : leaves) {
				int neighbor = *graph[leaf].begin();
				graph[neighbor].erase(leaf);
				if (graph[neighbor].size() == 1) {
					newLeaves.push_back(neighbor);
				}
			}
			leaves = newLeaves;
		}

		return leaves;
	}

};

class Solution {

	int dfs(unordered_map<int, vector<int>>& g, unordered_set<int>& v, int i, int path, int m)
	{
		v.insert(i);

		if (m < path)
		{
			return path;
		}

		int min = INT_MAX;

		for (int e : g[i])
		{
			if (v.count(e))
			{
				continue;
			}

			int r = dfs(g, v, e, path + 1, m);
			min = std::min(min, r);
		}

		return min;
	}

public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

		unordered_map<int, vector<int>> graph;

		for (const auto& e : edges)
		{
			graph[e[0]].push_back(e[1]);
			graph[e[1]].push_back(e[0]);
		}

		vector<int> ret;

		int min = INT_MAX;

		for (int i = 0; i < n; i++)
		{
			unordered_set<int> v;

			int r = dfs(graph, v, i, 0, min);

			if (r < min)
			{
				ret.clear();
				ret.push_back(i);
				min = r;
			}
			else if (r == min)
			{
				ret.push_back(i);
			}

		}

		return ret;
	}
};
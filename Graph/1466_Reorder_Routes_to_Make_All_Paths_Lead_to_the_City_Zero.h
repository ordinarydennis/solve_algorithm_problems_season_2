class Solution {
public:
	int count = 0;
	void bfs(int node, int n, vector<vector<pair<int, int>>>& adj) {
		queue<int> q;
		vector<bool> visit(n);
		q.push(node);
		visit[node] = true;

		while (!q.empty()) {
			node = q.front();
			q.pop();
			for (auto& [neighbor, sign] : adj[node]) {
				if (!visit[neighbor]) {
					count += sign;
					visit[neighbor] = true;
					q.push(neighbor);
				}
			}
		}
	}

	int minReorder(int n, vector<vector<int>>& connections) {
		vector<vector<pair<int, int>>> adj(n);
		for (auto& connection : connections) {
			adj[connection[0]].push_back({ connection[1], 1 });
			adj[connection[1]].push_back({ connection[0], 0 });
		}
		bfs(0, n, adj);
		return count;
	}
};


//https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/editorial/

class Solution {
public:
	int count = 0;
	void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {
		for (auto& [child, sign] : adj[node]) {
			if (child != parent) {
				count += sign;
				dfs(child, node, adj);
			}
		}
	}

	int minReorder(int n, vector<vector<int>>& connections) {
		vector<vector<pair<int, int>>> adj(n);
		for (auto& connection : connections) {
			adj[connection[0]].push_back({ connection[1], 1 });
			adj[connection[1]].push_back({ connection[0], 0 });
		}
		dfs(0, -1, adj);
		return count;
	}
};

https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/editorial/


class Solution {

	int ret = 0;

	void dfs(int node, int parent, vector<vector<pair<int, int>>>& mat)
	{
		for (auto& [adj, sign] : mat[node])
		{
			if (parent != adj)
			{
				ret += sign;
				dfs(adj, node, mat);
			}
		}
	}


public:
	int minReorder(int n, vector<vector<int>>& connections) {

		vector<vector<pair<int, int>>> mat(n);

		for (int i = 0; i < connections.size(); i++)
		{
			mat[connections[i][0]].push_back({ connections[i][1], 1 });
			mat[connections[i][1]].push_back({ connections[i][0], 0 });
		}

		dfs(0, -1, mat);

		return ret;
	}
};

class Solution {
public:
	int count = 0;
	void bfs(int node, int n, vector<vector<pair<int, int>>>& adj) {

		queue<int> q;

		q.push(node);

		vector<bool> visited(n, false);
		visited[0] = true;

		while (q.size())
		{
			int n = q.front();
			q.pop();

			for (auto& [child, sign] : adj[n])
			{
				if (false == visited[child])
				{
					visited[child] = true;
					count += sign;
					q.push(child);
				}
			}
		}
	}

	int minReorder(int n, vector<vector<int>>& connections) {

		vector<vector<pair<int, int>>> adj(n);

		for (auto& connection : connections) {
			adj[connection[0]].push_back({ connection[1], 1 });
			adj[connection[1]].push_back({ connection[0], 0 });
		}
		
		bfs(0, n, adj);
		return count;
	}
};

class Solution {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

		std::unordered_map<int, vector<pair<int, double>>> mat;

		for (int i = 0; i < edges.size(); i++)
		{
			mat[edges[i][0]].push_back({ edges[i][1] , succProb[i] });
			mat[edges[i][1]].push_back({ edges[i][0] , succProb[i] });
		}


		std::unordered_set<int> memo;

		std::queue<pair<int, double>> q;

		q.push(pair<int, double>{ start_node, 0.f });

		double ret = 0.0f;

		while (!q.empty())
		{

			int size = static_cast<int>(q.size());

			for (int i = 0; i < size; i++)
			{
				auto qp = q.front();
				q.pop();

				if (memo.count(qp.first))
				{
					continue;
				}
				memo.insert(qp.first);

				for (auto p : mat[qp.first])
				{
					q.push(pair<int, float>{ p.first, p.second * qp.second });
				}

				if (end_node == qp.first)
				{
					ret = std::max(ret, qp.second );
				}
			}
		}

		return ret;

	}
};

class Solution {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		vector<pair<int, double>>adj[n]; //Creating adjacency list
		for (int i = 0;i < edges.size();i++) {
			adj[edges[i][0]].push_back({ edges[i][1],succProb[i] });
			adj[edges[i][1]].push_back({ edges[i][0],succProb[i] });
		}
		priority_queue<pair<double, int>>pq; //Use maxHeap for path with the maximum probability
		pq.push({ 1.0,start }); //{probability,node}
		vector<double>dist(n, INT_MIN);
		dist[start] = 1;
		while (!pq.empty()) {
			auto itr = pq.top();
			pq.pop();
			double dis = itr.first;
			int node = itr.second;
			for (auto it : adj[node]) {
				int adjNode = it.first;
				double edW = it.second;
				if (dist[adjNode] < dis * edW) { //If greater probability is found then update probability of adjacent node & push adjacent node in maxHeap
					dist[adjNode] = dis * edW;
					pq.push({ dist[adjNode],adjNode });
				}
			}
		}
		if (dist[end] == INT_MIN) return 0.00000; //If there is no path from start to end
		else return dist[end];
	}
};

//https://leetcode.com/problems/path-with-maximum-probability/solutions/3691291/c-code-with-comments-dijkstra-algorithm/


class Solution {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

		unordered_map<int, vector<pair<int, double>>> mat;

		for (int i = 0; i < edges.size(); i++)
		{
			mat[edges[i][0]].push_back({ edges[i][1], succProb[i] });
			mat[edges[i][1]].push_back({ edges[i][0], succProb[i] });
		}

		queue<pair<int, double>> q;
		q.push({ start, 1.0 });

		vector<double> dist(n, 0.0);
		dist[start] = 1.0;

		while (!q.empty())
		{
			auto p = q.front();
			q.pop();

			int node = p.first;
			double d = p.second;

			for (auto [nextNode, nextProb] : mat[node])
			{
				if (dist[nextNode] < d * nextProb)
				{
					dist[nextNode] = d * nextProb;
					q.push({ nextNode, d * nextProb });
				}
			}
		}

		return dist[end];
	}
};

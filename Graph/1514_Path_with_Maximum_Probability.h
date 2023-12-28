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
					q.push(pair<int, float>{ p.first, p.second* qp.second });
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
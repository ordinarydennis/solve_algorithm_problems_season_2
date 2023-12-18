
//first approach(fail)
class Solution {

	int dfs(vector<vector<int>>& mat, int person, vector<int>& quiet)
	{
		int min = quiet[person];

		for (int i = 0; i < mat[person].size(); i++)
		{

			min = std::min(
				quiet[person],
				dfs(mat, mat[person][i], quiet)
			);

			mat[person] = min;
		}

		return min;

	}

public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {


		vector<vector<int>> mat(richer.size());

		for (int i = 0;i < richer.size(); i++)
		{
			mat[richer[i][1]].push_back(richer[i][0]);
		}

		vector<int> ret;

		for (int i = 0; i < quiet.size(); i++)
		{
			int m = dfs(mat, i, quiet);
			ret.push_back(m);
		}

		return ret;
	}
};

//second approach(success)
class Solution {

	int dfs(unordered_map<int, vector<int>>& rmap, int index, vector<int>& quiet, unordered_map<int, int>& memo)
	{
		if (memo.count(index))
		{
			return memo[index];
		}

		int min = quiet[index];

		int ret = index;

		for (int i : rmap[index])
		{
			int minIndex = dfs(rmap, i, quiet, memo);

			if (quiet[minIndex] < min)
			{
				min = quiet[minIndex];
				ret = minIndex;
			}
		}

		memo[index] = ret;

		return ret;
	}


public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

		unordered_map<int, vector<int>> rmap;
		unordered_map<int, int> memo;

		for (const auto r : richer)
		{
			rmap[r[1]].push_back(r[0]);
		}

		vector<int> ret;

		for(int i = 0; i < quiet.size(); i++)
		{
			ret.push_back(
				dfs(rmap, i, quiet, memo)
			);
		}

		return ret;
	}
};

//leetcode.com/problems/loud-and-rich/editorial/
//There are two kind of solution (bfs and dp)

class Solution {
public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int n = quiet.size();
		vector<int> indg(n, 0), ans(n, INT_MAX);
		vector<vector<int>> g(n);
		queue<int> q;

		//build graph and calculate indegrees
		for (int i = 0;i < richer.size();i++) {
			g[richer[i][0]].push_back(richer[i][1]);
			indg[richer[i][1]]++;
		}

		//initialise ans array and push nodes with 0 degrees into queue
		for (int i = 0;i < n;i++) {
			ans[i] = i;
			if (indg[i] == 0)
				q.push(i);
		}

		while (!q.empty()) {
			int curr = q.front();
			q.pop();

			for (int i : g[curr]) {
				//if parent node having more money is quieter , update
				if (ans[i] == INT_MAX || quiet[ans[i]] > quiet[ans[curr]])
					ans[i] = ans[curr];

				if (--indg[i] == 0)
					q.push(i);
			}
		}
		return ans;
	}
};

class Solution {
public:
	vector<int>dp;
	int dfs(int node, vector<vector<int>>& adj, vector<int>& quiet) {
		if (dp[node] != -1) return dp[node];

		int miniVal = quiet[node]; // if there is no outgoing edge from the node
		// then the node is the quitiest person he knows who is as rich 
		// as him 
		int miniNode = node;
		// stores the node with the properties

		for (auto it : adj[node]) {
			int miniIndex = dfs(it, adj, quiet);// do a dfs traversal for all the
			// adjNode
			if (quiet[miniIndex] < miniVal) {
				miniVal = quiet[miniIndex];
				miniNode = miniIndex;
			}

		}

		return dp[node] = miniNode;
	}
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int n = quiet.size();
		dp.resize(n, -1);
		vector<vector<int>>adj(n);
		vector<int>ans;
		for (auto it : richer) {
			adj[it[1]].push_back(it[0]);
		}

		for (int i = 0;i < n;i++) {
			int res = dfs(i, adj, quiet);
			ans.push_back(res);
		}
		return ans;
	}
};

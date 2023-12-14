
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

//leetcode.com/problems/loud-and-rich/editorial/
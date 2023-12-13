
class Solution {

	int dfs(vector<vector<int>>& mat, int person, vector<int>& quiet)
	{
		int min = INT_MAX;

		for (int i = 0; i < mat[person].size(); i++)
		{

			min = std::min(
				quiet[i],
				dfs(mat, mat[person][i], quiet)
			);
		}

		return min;

	}

public:
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {


		vector<vector<int>> mat(quiet.size() + 1);

		for (int i = 0;i < quiet.size(); i++)
		{
			mat[richer[1]].push_back(richer[0]);
		}

		vector<int> ret;

		for (int i = 0; i < quiet.size(); i++)
		{
			int m = dfs(vector<vector<int>>&mat, int person, vector<int>&quiet);
			ret.push_back(m);
		}

		return ret;
	}
};
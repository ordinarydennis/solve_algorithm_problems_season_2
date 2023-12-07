class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

		std::map <string, std::pair<string, float>>  mat;

		for (int i = 0; i < equations.size(); i++)
		{
			mat[equations[i][0]].first = equations[i][1];
			mat[equations[i][0]].second= values[i];
		}

		vector<double> ret;

		for (const auto& q : queries)
		{
			auto pair = mat[q[1]];

			float multi = 0.f;
			
			while (pair.first != q[0])
			{
				multi *= pair.second;

				pair.first = pair.first;
			}

			ret.push_back(multi);

		}

		return ret;
	}
};
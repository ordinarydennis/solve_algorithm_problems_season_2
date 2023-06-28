class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

		if (mat.size() * mat[0].size() != (r * c))
		{
			return mat;
		}
		
		vector<vector<int>> ret;

		int count = 0;

		std::vector<int> list;

		for (int a = 0; a < mat.size(); a++)
		{
			for (int b = 0; b < mat[0].size(); b++)
			{
				count++;

				list.push_back(mat[a][b]);

				if (0 == (count % c))
				{
					ret.push_back(std::move(list));
					count = 0;
				}
			}
		}

		return ret;

	}
};
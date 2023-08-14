class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {

		vector<vector<int>> ret;

		for (int c = 0; c < cols; c++)
		{
			vector<int> co;

			for (int r = 0; r < rows; r++)
			{
				co.push_back(abs(rCenter - r));
				co.push_back(abs(cCenter - c));
				ret.push_back(std::move(co));
			}
		}

		return ret;
	}
};
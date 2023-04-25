class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {

		int xMax = INT_MIN;
		int yMax = INT_MIN;

		for (int y = 0; y < grid.size(); y++)
		{
			int xSize = grid[y].size();

			for (int x = 0; x < xSize; x++)
			{
				if (grid[y][x])
				{
					xMax = std::max(xMax, x);
					yMax = std::max(yMax, y);
				}
			}
		}

		return (xMax + 1) * (yMax + 1);
	}
};
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {

		int islandCount = 0;
		int adjacentIslandCount = 0;


		for (int y = 0; y < grid.size(); y++)
		{
			int xSize = grid[y].size();

			for (int x = 0; x < xSize; x++)
			{
				if (grid[y][x])
				{
					islandCount++;

					if (y && grid[y - 1][x])
					{
						adjacentIslandCount++;
					}
					if (x && grid[y][x - 1])
					{
						adjacentIslandCount++;
					}
				}
			}
		}

		return islandCount * 4 - adjacentIslandCount * 2;
	}
};


//https://leetcode.com/problems/island-perimeter/solutions/95126/c-solution-with-explanation/?orderBy=most_votes
class Solution {

	int searchPath(vector<vector<int>>& obstacleGrid, int x, int y, vector<vector<int>>& mat)
	{
		if (obstacleGrid.size() <= y) return 0;

		if (obstacleGrid[y].size() <= x) return 0;

		if (-1 != mat[y][x]) return mat[y][x];

		if (1 == obstacleGrid[y][x]) return 0;

		if (obstacleGrid.size() - 1 == y && obstacleGrid[y].size() - 1 == x) return 1;

		mat[y][x] = searchPath(obstacleGrid, x + 1, y, mat) + searchPath(obstacleGrid, x, y + 1, mat);

		return mat[y][x];
	}

public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		vector<vector<int>> mat(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));

		return searchPath(obstacleGrid, 0, 0, mat);

	}
};

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int r = obstacleGrid.size();
		int c = obstacleGrid[0].size();
		int a[r][c];
		bool flag = false;
		if (obstacleGrid[0][0] == 1 || obstacleGrid[r - 1][c - 1] == 1)
			return 0;
		for (int i = 0; i < c; i++) {
			if (flag || obstacleGrid[0][i]) { //presence of obstacle in the cell or previous cells in the row
				a[0][i] = 0;
				flag = true;
			}
			else
				a[0][i] = 1;
		}

		flag = false;

		for (int j = 1; j < r; j++) {
			if (flag || obstacleGrid[j][0]) {//presence of obstacle in the cell or previous cells in the column
				a[j][0] = 0;
				flag = true;
			}
			else
				a[j][0] = 1;
		}
		for (int i = 1; i < r; i++)
			for (int j = 1; j < c; j++) {
				if (obstacleGrid[i][j] == 1)//obstacle
					a[i][j] = 0;
				else
					a[i][j] = a[i][j - 1] + a[i - 1][j];//can reach (i, j) through (i, j-1) or (i-1, j)
			}
		return a[r - 1][c - 1];
	}
};

//https://leetcode.com/problems/unique-paths-ii/solutions/3900740/efficient-c-method-for-unique-path-2-dynamic-programming/
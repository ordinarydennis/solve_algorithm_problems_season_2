class Solution {

	int ableCount = 0;
	int disableCount = 0;

	void dfs(int maxN, int maxK, int k, int row, int column)
	{
		if (row < 0 || column < 0)
		{
			disableCount++;
			return;
		}

		if (k == maxK)
		{
			if (row <= maxN - 1 && column <= maxN - 1)
			{
				ableCount++;
			}

			return;
		}

		dfs(maxN, maxK, k + 1, row + 2, column - 1);
		dfs(maxN, maxK, k + 1, row + 2, column + 1);

		dfs(maxN, maxK, k + 1, row + 1, column + 2);
		dfs(maxN, maxK, k + 1, row - 1, column + 2);

		dfs(maxN, maxK, k + 1, row - 2, column + 1);
		dfs(maxN, maxK, k + 1, row - 2, column - 1);

		dfs(maxN, maxK, k + 1, row - 1, column - 2);
		dfs(maxN, maxK, k + 1, row + 1, column - 2);

	}


public:
	double knightProbability(int n, int k, int row, int column) {

		dfs(n, k, 0, row, column);

		return ableCount / (ableCount + disableCount);
	}
};

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


class Solution {

	unordered_map<string, double> mp;

	int dir[8][8] = { {-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1} };

public:
		
	double knightProbability(int n, int k, int row, int column)
	{
		return find(n, k, row, column);
	}

	double find(int n, int moves, int r, int c)
	{
		if (r < 0 || r >= n || c < 0 || c >= n)
			return false;

		if (moves == 0)
			return 1;//if the knight does not moves then he is definitely in that pos

		//we will make unique key for each move and store that prob in this key
		string key = to_string(r) + "_" + to_string(c) + "_" + to_string(moves);

		if (mp.find(key) != mp.end())
			return mp[key];

		double probability = 0;

		for (int i = 0; i < 8; i++)
			probability += find(n, moves - 1, r + dir[i][0], c + dir[i][1]) / 8.0;
		//moves-1 as we have taken 1 move here and adding the direction in which we are now

		mp[key] = probability;
		return mp[key];
	}
};

//https://leetcode.com/problems/knight-probability-in-chessboard/solutions/889598/c-dp-solution-explained/?orderBy=most_votes

//Also read the solution solved with bfs.

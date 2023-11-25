class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {

		vector<vector<int>> ret(n, vector<int>(n));

		int xmin = 0, ymin = 0, xmax = n - 1, ymax = n - 1;

		int i = 1;

		while (i <= n * n)
		{
			for (int x = xmin; x <= xmax; x++) ret[ymin][x] = i++;
			ymin++;

			for (int y = ymin; y <= ymax; y++) ret[y][xmax] = i++;
			xmax--;

			for (int x = xmax; xmin <= x; x--) ret[ymax][x] = i++;
			ymax--;

			for (int y = ymax; ymin <= y; y--) ret[y][xmin] = i++;
			xmin++;
		}

		return ret;

	}
};
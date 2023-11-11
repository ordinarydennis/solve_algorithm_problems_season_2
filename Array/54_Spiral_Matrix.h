class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		int xmin = 0;
		int xmax = matrix[0].size() - 1;
		int ymin = 0;
		int ymax = matrix.size() - 1;


		int dir = 0;

		vector<int> ret;

		while (true)
		{
			if (0 == dir && xmin <= xmax)
			{
				int x = xmin;

				while (x <= xmax)
				{
					ret.push_back(matrix[ymin][x]);
					x++;
				}

				ymin++;

				dir = 1;
			}

			if (1 == dir && ymin < ymax)
			{
				int y = ymin;

				while (y <= ymax)
				{
					ret.push_back(matrix[y][xmax]);

					y++;
				}

				xmax--;

				dir = 2;
			}

			if (2 == dir && xmin < xmax)
			{
				int x = xmax;

				while (xmin <= x)
				{
					ret.push_back(matrix[ymax][x]);
					x--;
				}

				ymax--;

				dir = 3;
			}

			if (3 == dir && ymin < ymax)
			{
				int y = ymax;

				while (ymin <= y)
				{
					ret.push_back(matrix[y][xmin]);
					y--;
				}

				xmin++;

				dir = 0;
			}

			if (ymin == ymax && xmin == xmax)
			{
				break;
			}
		}

		return ret;
	}
};
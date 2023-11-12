class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		int xmin = 0;
		int ymin = 0;
		int xmax = matrix[0].size() - 1;
		int ymax = matrix.size() - 1;

		std::vector<int> ret((xmax + 1) * (ymax + 1));

		int index = 0;

		while (xmin <= xmax && ymin <= ymax)
		{
			for (int i = xmin; i <= xmax; i++)
				ret[index++] = matrix[ymin][i];

			if (++ymin > ymax) break;

			for (int i = ymin; i <= ymax; i++)
				ret[index++] = matrix[i][xmax];

			if (--xmax < xmin) break;

			for (int i = xmax; xmin <= i; i--)
				ret[index++] = matrix[ymax][i];

			if (--ymax < ymin) break;
			
			for (int i = ymax; ymin <= i; i--)
				ret[index++] = matrix[i][xmin];

			if (++xmin > xmax) break;
		}

		return ret;
	}
};

//https://leetcode.com/problems/spiral-matrix/solutions/20719/c-spiral-traverse/
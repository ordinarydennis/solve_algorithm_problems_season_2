class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		int t = 0; 
		int b = 0; 
		int l = 0; 
		int r = 0;

		int x = 0; 
		int y = 0; 

		int maxX = matrix.size();
		int maxY = matrix[0].size();

		vector<int> ret;

		ret.reserve(maxX * maxY);

		while (1)
		{
			while (x < maxX - r)
			{
				ret.push_back(matrix[y][x++]);
			}

			x--;
			t++;

			while (y < maxY - b)
			{
				ret.push_back(matrix[++y][x]);
			}

			y--;
			r++;

			while (l <= x)
			{
				ret.push_back(matrix[y][--x]);
			}

			x++;
			b++;

			while (t <= y)
			{
				ret.push_back(matrix[--y][x]);
			}

			y++;
			l++;

			if (ret.size() == maxX * maxY)
			{
				break;
			}
		}

		return ret;
	}
};
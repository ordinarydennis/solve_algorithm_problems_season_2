class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {

		int maxX = matrix[0].size() - 1;
		int maxY = matrix.size() - 1;


		for (int y = 0; y <= maxY; y++)
		{
			for (int x = 0; x <= maxX; x++)
			{
				int itY = y;
				int itX = x;

				int pre = matrix[itY][itX];

				while (itY <= maxY && itX <= maxX)
				{
					if (pre != matrix[itY][itX])
					{
						return false;
					}
					

					itY++;
					itX++;
				}
				
			}
		}

		return true;
	}
};

//read soluton
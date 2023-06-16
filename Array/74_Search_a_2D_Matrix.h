//solution
//https://leetcode.com/problems/search-a-2d-matrix/solutions/26219/binary-search-on-an-ordered-matrix/
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		int row_num = matrix.size();
		int col_num = matrix[0].size();

		int begin = 0, end = row_num * col_num - 1;

		while (begin <= end)
		{
			int mid = (begin + end) / 2;

			int mid_value = matrix[mid / col_num][mid % col_num];

			if (mid_value == target)
			{
				return true;
			}
			else if (mid_value < target)
			{
				begin = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}

		return false;
	}
};

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		int maxY = matrix.size();
		int maxX = matrix[0].size();


		std::vector<int> nList;

		nList.reserve(maxX * maxY);

		for (int y = 0; y < matrix.size(); y++)
		{
			for (int x = 0; x < maxX; x++)
			{
				nList.push_back(matrix[y][x]);
			}
		}

		auto it =  std::find(nList.begin(), nList.end(), target);

		return nList.end() != it;

	}
};

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		int maxY = matrix.size() - 1;
		int minY = 0;

		int maxX = matrix[0].size() - 1;

		int midY = 0;

		while (minY < maxY)
		{
			midY = (maxY + minY) / 2;

			if (target < matrix[midY][maxX])
			{
				maxY = midY - 1;

				if (0 == maxY)
				{
					break;
				}
			}
			else if(target > matrix[midY][maxX])
			{
				minY = midY + 1;

				if (matrix.size() - 1 <= midY)
				{
					break;
				}
			}
			else
			{
				return true;
			}
		}

		midY = (maxY + minY) / 2;

		return matrix[midY].end() != std::find(matrix[midY].begin(), matrix[midY].end(), target);
	}
};
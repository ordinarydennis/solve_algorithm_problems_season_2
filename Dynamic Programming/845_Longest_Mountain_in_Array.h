Input: arr = [2, 1, 4, 7, 3, 2, 5]
Output : 5

class Solution {
public:
	int longestMountain(vector<int>& arr) {

		int ret = 0;


		for (int i = 0; i < arr.size(); i++)
		{
			int preL = INT_MAX;
			int lIndex = i - 1;
			preL = arr[i];

			int preR = INT_MAX;
			int rIndex = i + 1;
			preR = arr[i];

			int count = 0;

			bool exitLoopL = false;
			bool exitLoopR = false;

			while (true)
			{
				if (0 <= lIndex)
				{
					if (preL > arr[lIndex])
					{
						lIndex--;
						preL = arr[lIndex];
						count++;
					}
					else
					{
						exitLoopL = true;
					}
				}
				else
				{
					exitLoopL = true;
				}

				if (rIndex < arr.size() - 1)
				{
					if (preR > arr[rIndex])
					{
						rIndex++;
						preR = arr[rIndex];
						count++;
					}
					else
					{
						exitLoopR = true;
					}
				}
				else
				{
					exitLoopR = true;
				}

				if (exitLoopL && exitLoopR)
				{
					break;
				}
			}

			ret = std::max(ret, count);
		}

		return ret + 1;
	}
};
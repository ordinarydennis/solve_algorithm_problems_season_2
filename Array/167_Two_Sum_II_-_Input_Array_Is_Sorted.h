class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {

		//vector<int> numList;
		//numList.reserve(numbers.size());

		//int i = 0;

		//while (numbers[i] <= target && i < numbers.size())
		//{
		//	numList.push_back(numbers[i]);
		//	i++;
		//}


		int start = 0;
		int end = numbers.size() - 1;

		vector<int> ret;

		while (start < end)
		{

			if (target < numbers[start] + numbers[end])
			{
				end--;
			}
			else if (numbers[start] + numbers[end] < target)
			{
				start++;
			}
			else
			{
				ret.push_back(start + 1);
				ret.push_back(end + 1);
				break;
			}
		}

		return ret;
	}
};
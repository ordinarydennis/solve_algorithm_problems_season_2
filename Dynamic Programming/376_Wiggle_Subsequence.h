class Solution {

	int calculate(vector<int>& nums, int index, bool isUp)
	{
		int maxcount = 0;

		for (int i = index + 1; i < nums.size(); i++)
		{
			if ((isUp && nums[i] > nums[index]) || (!isUp && nums[i] < nums[index]))
			{
				maxcount = std::max(maxcount, 1 + calculate(nums, i, !isUp));
			}

		}
		return maxcount;
	}

public:
	int wiggleMaxLength(vector<int>& nums) {

		if (nums.size() < 2)
			return nums.size();


		return 1 + std::max(calculate(nums, 0, true), calculate(nums, 0, false));
	}
};

Example 1:

Input: nums = [1, 7, 4, 9, 2, 5]
Output : 6
Explanation : The entire sequence is a wiggle sequence with differences(6, -3, 5, -7, 3).
Example 2 :

	Input : nums = [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
	Output : 7
	Explanation : There are several subsequences that achieve this length.
	One is[1, 17, 10, 13, 10, 16, 8] with differences(16, -7, 3, -3, 6, -8).
	Example 3 :

	Input : nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
	Output : 2


	Constraints :

	1 <= nums.length <= 1000
	0 <= nums[i] <= 1000
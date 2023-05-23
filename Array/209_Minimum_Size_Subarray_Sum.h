class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {

		std::sort(nums.begin(), nums.end(), greater<int>());

		int sum = 0;

		int ret = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];

			if (target <= sum)
			{
				ret = i + 1;
				break;
			}
		}

		return ret;

	}
};

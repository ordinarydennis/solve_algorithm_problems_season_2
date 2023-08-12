//first solution
class Solution {
public:
	int smallestRangeI(vector<int>& nums, int k) {

		std::sort(nums.begin(), nums.end());

		int i = 0;

		while (1)
		{
			int a = nums[nums.size() - 1] - k + i;
			int b = nums[0] + k;

			if (a - b < 0)
			{
				i++;
			}
			else
			{
				return a - b;
			}
			
		}
		
		return 0;
	}
};

//second solution
class Solution {
public:
	int smallestRangeI(vector<int>& nums, int k) {

		std::sort(nums.begin(), nums.end());

		int ret = (nums[nums.size() - 1] - k) - nums[0] - k;

		return 0 < ret ? ret : 0;

	}
};
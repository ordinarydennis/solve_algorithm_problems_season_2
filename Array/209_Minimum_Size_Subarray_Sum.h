class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {

		int l = 0;
		int r = 0;

		int length = nums.size();

		int ret = INT_MAX;

		int sum = 0;

		while (r < length)
		{
			sum += nums[r++];

			while (target <= sum)
			{
				ret = std::min(ret, r - l);
				sum -= nums[l++];
			}
		}

		return (INT_MAX == ret) ? 0 : ret;
	}
};

//https://leetcode.com/problems/minimum-size-subarray-sum/solutions/59090/c-o-n-and-o-nlogn/
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

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {

		int n = nums.size(), len = INT_MAX;

		vector<int> sums(n + 1, 0);
		
		for (int i = 1; i <= n; i++)
		{
			sums[i] = sums[i - 1] + nums[i - 1];
		}

		for (int i = n; i >= 0 && sums[i] >= target; i--)
		{
			int j = upper_bound(sums.begin(), sums.end(), sums[i] - target) - sums.begin();
			len = min(len, i - j + 1);
		}

		return len == INT_MAX ? 0 : len;
	}
};

//https://leetcode.com/problems/minimum-size-subarray-sum/solutions/59090/c-o-n-and-o-nlogn/
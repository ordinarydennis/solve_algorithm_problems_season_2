class Solution {

	double sumOfNums(vector<int>& nums, int k, std::vector<int>& sum, std::vector<std::vector<double>>& memo, int len, int s)
	{
		if (memo[s][k] != 0) 
			return memo[s][k];

		if (k == 1)
		{
			memo[s][k] = ((double)(sum[len - 1] - sum[s] + nums[s]) / (len - s));
			return memo[s][k];
		}

		for (int i = s; i + k <= len; i++)
		{
			memo[s][k] = std::max(
				memo[s][k], 
				((double)(sum[i] - sum[s] + nums[s]) / (i - s + 1)) + sumOfNums(nums, k - 1, sum, memo, len, i + 1)
			);
		}
		return memo[s][k];
	}

public:
	double largestSumOfAverages(vector<int>& nums, int k) {

		std::vector<int> sum(nums.size(), 0);

		std::vector<std::vector<double>> memo(nums.size(), std::vector<double>(k + 1, 0));

		for (int i = 0; i < nums.size(); i++)
		{
			sum[i] = (0 < i) ? sum[i - 1] + nums[i] : nums[i];
		}

		return sumOfNums(nums, k, sum, memo, nums.size(), 0);

	}
};

https://leetcode.com/problems/largest-sum-of-averages/solutions/126280/naive-detailed-step-by-step-approach-from-recursive-to-dp-o-n-solution/?orderBy=most_votes
class Solution {

public:
	int findNumberOfLIS(vector<int>& nums) {

		int n = nums.size(), res = 0, max_len = 0;

		vector<pair<int, int>> dp(n, { 1, 1 });            //dp[i]: {length, number of LIS which ends with nums[i]}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
				{
					if (dp[i].first == dp[j].first + 1)
						dp[i].second += dp[j].second;

					if (dp[i].first < dp[j].first + 1)
						dp[i] = { dp[j].first + 1, dp[j].second };
				}
			}

			if (max_len == dp[i].first)
				res += dp[i].second;

			if (max_len < dp[i].first)
			{
				max_len = dp[i].first;
				res = dp[i].second;
			}
		}

		return res; 
	}
};

[1, 3, 5, 4, 7]

//https://leetcode.com/problems/number-of-longest-increasing-subsequence/solutions/1230468/c-clean-dp-solution-easy-and-explained/?orderBy=most_votes
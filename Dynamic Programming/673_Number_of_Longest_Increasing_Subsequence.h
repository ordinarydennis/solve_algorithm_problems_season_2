class Solution {

	std::unordered_map<int, int> memo;

	int totlaMax = 0;

	int dfs(vector<int>& nums, int index)
	{
		if (index <= nums.size())
		{
			memo[index] = 0;
			return 0;
		}

		if (memo[index])
		{
			return memo[index];
		}

		int max = 0;

		int pre = nums[index];

		for (int i = index + 1; i < nums.size(); i++)
		{
			if (nums[i] < pre)
			{
				continue;
			}

			int m = 1 + dfs(nums, i);

			if (max < m)
			{
				memo[i] = m;
				max = m;
				totlaMax = std::max(totlaMax, max);
			}

			pre = nums[i];

		}

		return max;
	}

public:
	int findNumberOfLIS(vector<int>& nums) {


		dfs(nums, 0);

		int ret = 0;

		for (const auto [i, count] : memo)
		{
			if (totlaMax == count)
			{
				ret++;
			}
		}

		return  ret++;

	}
};

[1, 3, 5, 4, 7]
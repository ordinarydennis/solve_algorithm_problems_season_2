class Solution {

	std::unordered_map<int, int> memo;

	int dfs(const vector<int>& nums, int index)
	{
		if (0 < memo[index])
		{
			return memo[index];
		}

		if (nums.size() <= index)
			return 0;

		int sum = 0;
		int i = index;

		while (i < nums.size() && nums[i] == nums[index])
		{
			sum += nums[i];
			i++;
		}

		while (i < nums.size() && nums[i] == nums[index] + 1)
		{
			i++;
		}

		memo[index] = std::max(sum + dfs(nums, i), dfs(nums, index + 1));

		return memo[index];
	}

public:
	int deleteAndEarn(vector<int>& nums) {

		std::sort(nums.begin(), nums.end());

		return dfs(nums, 0);
	}
};

// https://leetcode.com/problems/delete-and-earn/solutions/1820279/c-detailed-explanation-w-recursion-to-memoziation-understand-concept/
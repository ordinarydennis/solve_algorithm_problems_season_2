class Solution {

	std::unordered_map<int, int> memo;

	int dfs(vector<int>& nums, int index)
	{
		if (nums.size() <= index)
		{
			return -1;
		}

		if (index == nums.size() - 1)
		{
			return 0;
		}

		if (0 == nums[index])
		{
			return -1;
		}

		if (memo.count(index))
		{
			return memo[index];
		}

		int min = INT_MAX;

		for (int i = 1; i <= nums[index]; i++)
		{
			int length = dfs(nums, index + i);

			if (-1 != length)
			{
				min = std::min(min, length);
				memo[index + i] = min;
			}
		}

		return min == INT_MAX ? -1 : min + 1;
	}


public:
	int jump(vector<int>& nums) {

		return dfs(nums, 0);

	}
};

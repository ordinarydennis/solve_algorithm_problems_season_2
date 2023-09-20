class Solution {

	std::unordered_map<int, int> m;

	int dfs(const vector<int>& nums, int index)
	{
		if (m.count(index))
		{
			return m[index];
		}

		if (nums.size() <= index)
		{
			return 0;
		}

		int cur = nums[index];
		int i = index + 1;
		int sum = cur;

		while (i < nums.size() && cur ==  nums[i])
		{
			sum += nums[i];
			i++;
		}

		while (i < nums.size() && cur + 1 == nums[i])
		{
			i++;
		}

		m[index] = std::max(sum + dfs(nums, i), dfs(nums, index + 1));

		return m[index];
	}


public:
	int deleteAndEarn(vector<int>& nums) {

		std::sort(nums.begin(), nums.end());

		return dfs(nums, 0);
	}
};

https://leetcode.com/problems/delete-and-earn/solutions/1820279/c-detailed-explanation-w-recursion-to-memoziation-understand-concept/
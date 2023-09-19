class Solution {

	int max = 0;

	void dfs(const vector<int>& nums, std::unordered_set<int>& memo, int sum, vector<bool>& checked, int next)
	{
		if (nums.size() <= next)
		{
			max = std::max(max, sum);
			return;
		}
		
		for (int i = 0; i < nums.size(); i++)
		{
			if (checked[i])
			{
				continue;
			}

			if (memo.count(nums[i]))
			{
				continue;
			}

			memo.insert(nums[i] - 1);
			memo.insert(nums[i] + 1);

			checked[i] = true;

			dfs(nums, memo, nums[i] + sum, checked, i + 1);

			checked[i] = false;

			memo.erase(nums[i] - 1);
			memo.erase(nums[i] + 1);
		}
	}


public:
	int deleteAndEarn(vector<int>& nums) {

		std::unordered_set<int> memo;

		vector<bool> checked(nums.size(), false);

		dfs(nums, memo, 0, checked, 0);

		return max;
	}
};
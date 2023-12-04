class Solution {

	bool dfs(vector<int>& nums, int index, vector<bool>& memo)
	{
		if (false == memo[index]) return false;

		if (nums.size() - 1 == index) return true;

		if (nums.size() <= index) return false;

		if (nums[index] < 1) return false;
				
		for (int i = 1; i <= nums[index]; i++)
		{
			if (dfs(nums, index + i, memo)) return true;
			
			memo[index + i] = false;
		}
			
		return false;
	}


public:
	bool canJump(vector<int>& nums) {

		vector<bool> memo(nums.size(), true);

		return dfs(nums, 0, memo);

	}
};

class Solution {
public:
	bool canJump(vector<int>& nums) {

		int m = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (m < i) return false;

			m = max(m, i + nums[i]);

			if (nums.size() - 1 <= m) return true;
		}

		return false;
	}
};
//https://leetcode.com/problems/jump-game/solutions/20917/linear-and-simple-solution-in-c/

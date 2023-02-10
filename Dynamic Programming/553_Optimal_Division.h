class Solution {

	vector<bool> checks;

	string max = 0.f;

	void calc(vector<int>& nums, int pos, float f)
	{
		if (nums.size() < pos)
		{
			max = std::max(max, f);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (false == checks[i])
			{
				checks[i] = true;

				if (0 == f)
				{
					calc(nums, pos + 1, nums[i]);
				}
				else
				{
					calc(nums, pos + 1, f / nums[i]);
				}

				checks[i] = false;
			}
		}

	}

public:
	string optimalDivision(vector<int>& nums) {

		checks.resize(nums.size());

		calc(nums, 0, 0.f);

		return max;
	}
};

//read solution https://leetcode.com/problems/optimal-division/solutions/127534/optimal-division/?orderBy=most_votes
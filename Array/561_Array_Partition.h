class Solution {
public:
	int arrayPairSum(vector<int>& nums) {

		sort(nums.begin(), nums.end());

		int ret = 0;

		for (int i = 0; i < nums.size();)
		{
			ret += nums[i];
			i += 2;
		}

		return ret;
	}
};


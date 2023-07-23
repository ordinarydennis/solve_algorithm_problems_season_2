class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& nums) {

		std::vector<bool> ret;

		ret.reserve(nums.size());

		int num = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			num = (num * 2 + nums[i]) % 5; //Modulo Space..
			ret.push_back(0 == num);
		}

		return ret;
	}
};

//https://leetcode.com/problems/binary-prefix-divisible-by-5/solutions/265601/detailed-explanation-using-modular-arithmetic-o-n/

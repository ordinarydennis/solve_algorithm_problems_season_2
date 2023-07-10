//solution
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& nums) {

		int ei = 0;
		int oi = 1;

		std::vector<int> ret(nums.size());

		for (int i = 0; i <nums.size(); i++)
		{
			if (nums[i] % 2 == 0)
			{
				ret[ei] = nums[i];
				ei += 2;
			}
			else
			{
				ret[oi] = nums[i];
				oi += 2;
			}
		}

		return ret;
	}
};
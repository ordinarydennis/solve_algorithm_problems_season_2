class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& nums) {

		std::vector<bool> ret;

		ret.reserve(nums.size());

		for (int k = 0; k < nums.size(); k++)
		{
			int64_t s = 0;

			for (int i = k; 0 <= i; i--)
			{
				if (1 == nums[i])
				{
					int e = k - i;
					s += pow(2, e);
				}
			}

			ret.push_back(0 == (s % 5));
		}

		return ret;
	}
};
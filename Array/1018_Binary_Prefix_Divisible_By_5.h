class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& nums) {

		vector<bool> ret;

		int sum = 0;

		for (int i= 0; i < nums.size(); i++)
		{
			if (i == 0)
			{
				sum += nums[i];
			}
			else
			{
				sum = sum << 1;
				sum += nums[i];
				sum = sum % 5;
			}

			ret.push_back(0 == sum % 5);
		   
		}

		return ret;
	}
};
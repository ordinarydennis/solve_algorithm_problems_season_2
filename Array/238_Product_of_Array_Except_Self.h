class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {

		vector<int> ret(nums.size(), 1);

		for (int a = 0; a < nums.size(); a++)
		{
			int p = 1;

			for (int b = 0; b < nums.size(); b++)
			{
				if (a != b)
				{
					p = p * nums[b];
				}
			}

			ret[a] = p;
		}

		return ret;

	}
};

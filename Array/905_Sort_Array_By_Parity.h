class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {

		vector<int> ret(nums.size(), 0);

		int eI = 0;
		int oI = nums.size() - 1;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] % 2 == 0)
			{
				ret[eI] = nums[i];
				eI++;
			}
			else
			{
				ret[oI] = nums[i];
				oI--;
			}
		}

		return ret;

	}
};
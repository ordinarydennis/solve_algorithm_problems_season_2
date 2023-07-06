class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {

		int oI = 0;

		for (int oI = 0, i = 0; i < nums.size(); i++)
		{
			if (0 == nums[i] % 2)
				std::swap(nums[i], nums[oI++]);
		}

		return nums;
	}
};
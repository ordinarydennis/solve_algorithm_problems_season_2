class Solution {
public:
	bool isMonotonic(vector<int>& nums) {

		bool isInc = true, isDec = true;

		for (int i = 1; i < nums.size(); i++)
		{
			isInc &= nums[i] >= nums[i - 1];
			isDec &= nums[i] <= nums[i - 1];
		}

		return isInc || isDec;
	}
};
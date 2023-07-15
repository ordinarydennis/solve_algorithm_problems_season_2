class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {

		int l = 0, r = nums.size() - 1, i = nums.size() - 1;

		std::vector<int> ret(nums.size());
		
		while (l <= r)
			ret[i--] = abs(nums[l]) < abs(nums[r]) ? nums[r] * nums[r--] : nums[l] * nums[l++];

		return ret;
	}
};
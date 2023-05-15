class Solution {
public:
	int maximumProduct(vector<int>& nums) {

		std::sort(nums.begin(), nums.end());

		return std::max(
			nums[0] * nums[1] * nums[nums.size() - 1],
			nums[nums.size() - 3] * nums[nums.size() - 2] * nums[nums.size() - 1]
		);

	}
};
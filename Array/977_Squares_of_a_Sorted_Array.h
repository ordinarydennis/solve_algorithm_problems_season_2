class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {

		vector<int> ret(nums.size(), 0);

		int i = nums.size() - 1;
		int l = 0;
		int r = nums.size() - 1;

		while (l <= r)
			ret[i--] = (nums[l] * nums[l] < nums[r] * nums[r]) ? nums[r] * nums[r--] : nums[l] * nums[l++];

		return ret;
	}
};

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++)
		{
			nums[i] = nums[i] * nums[i];
		}

		std::sort(nums.begin(), nums.end());

		return nums;
	}
};
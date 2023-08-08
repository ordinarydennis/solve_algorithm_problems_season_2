class Solution {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {

		std::sort(nums.begin(), nums.end());

		//flip just negative integer to positive integer.
		for (int i= 0; 0 < k && i < nums.size() && nums[i] < 0; i++, k--)
			nums[i] = -nums[i];


		//if the k remaining is odd, need to subtract minimum value from total.
		return accumulate(nums.begin(), nums.end(), 0) + 2 * (-1 * (k % 2) * *min_element(nums.begin(), nums.end()));
	}
};

//https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/solutions/252254/java-c-python-sort/
class Solution {
public:
	int findDuplicate(vector<int>& nums) {

		/*std::unordered_set<int> checker;

		for (int n : nums)
		{
			if (checker.count(n))
			{
				return n;
			}
			checker.insert(n);
		}*/

		std::sort(nums.begin(), nums.end());

		for (int i = 1; i < nums.size(); i++)
		{
			if (0 == (nums[i] - nums[i - 1]))
			{
				return nums[i];
			}
		}

		return 0;

	}
};
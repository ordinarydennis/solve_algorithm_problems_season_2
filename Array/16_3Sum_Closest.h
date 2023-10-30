class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {

		std::sort(nums.begin(), nums.end());

		int len = nums.size() - 1;

		int ret = nums[0] + nums[1] + nums[2];

		for(int a = 0; a < len - 1; a++)
		{
			int l = a + 1;
			int r = len;

			while (l < r)
			{
				int sum = nums[a] + nums[l] + nums[r];

				if (sum < target) l++;
				else if (sum > target) r--;
				else return sum;
				
				if (std::abs(sum - target) < std::abs(ret - target)) ret = sum;
			}
		}

		return ret;
	}
};
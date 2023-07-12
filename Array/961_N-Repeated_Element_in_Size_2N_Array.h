class Solution {
public:
	int repeatedNTimes(vector<int>& nums) {

		int n = nums.size() / 2;

		std::unordered_map<int,int> map;

		for (int i = 0; i < nums.size(); i++)
		{
			if (++map[nums[i]] == n)
			{
				return nums[i];
			}
		}

		return 0;
	}
};
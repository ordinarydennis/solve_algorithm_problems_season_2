class Solution {
public:
	void moveZeroes(vector<int>& nums) {

		vector<int> nums2;

		nums2.reserve(nums.size());

		int count = 0;

		for (int i = 0; i < nums.size() + count; i++)
		{
			if (i < nums.size())
			{
				if (0 == nums[i])
				{
					count++;
				}
				else
				{
					nums2.push_back(nums[i]);
				}
			}
			else
			{
				nums2.push_back(0);
			}
		}

		nums = std::move(nums2);

	}
};
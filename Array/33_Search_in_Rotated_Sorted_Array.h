class Solution {

	void search(vector<int>& nums, int start, int end, int target, int& ret)
	{
		if (end <= start)
		{
			if (nums[start] == target)
			{
				ret = start;
			}
			return;
		}

		int mid = (start + end) / 2;

		search(nums, start, mid, target, ret);

		if (-1 == ret)
		{
			search(nums, mid + 1, end, target, ret);
		}
	}

public:
	int search(vector<int>& nums, int target) {

		int ret = -1;

		search(nums, 0, nums.size() - 1, target, ret);

		return ret;
	}
};
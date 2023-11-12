
//second approach
class Solution {

public:
	int search(vector<int>& nums, int target) {

		int l = 0;
		int r = nums.size() - 1;

		while (l <= r)
		{
			int mid = (l + r) / 2;

			if (nums[mid] == target)
				return mid;

			if (nums[l] <= nums[mid])
			{
				if (nums[l] <= target && target <= nums[mid])
					r = mid;
				else
					l = mid + 1;
			}
			else
			{
				if (nums[mid] < target && target <= nums[r])
					l = mid + 1;
				else
					r = mid;
			}
		}

		return -1;
	}
};

//https://leetcode.com/problems/search-in-rotated-sorted-array/solutions/3879263/100-binary-search-easy-video-o-log-n-optimal-solution/


//first approach
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



class Solution {
public:
	int search(vector<int>& nums, int target) {

		int l = 0;
		int r = nums.size() - 1;

		while(l <= r)
		{
			int mid = (l + r) / 2;

			if (target == nums[mid])
				return mid;

			if (nums[l] <= nums[mid])
			{
				if (nums[l] <= target && target <= nums[mid])
				{
					r = mid;
				}
				else
				{
					l = mid + 1;
				}
			}
			else
			{
				if (nums[mid + 1] <= target && target <= nums[r])
				{
					l = mid + 1;
				}
				else
				{
					r = mid;
				}
			}
		}

		return -1;
	}
};
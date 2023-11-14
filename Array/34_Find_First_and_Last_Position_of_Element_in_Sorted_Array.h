class Solution {

public:
    vector<int> searchRange(vector<int>& nums, int target) {

		vector<int> ret(2, -1);

		if (0 == nums.size())
		{
			return ret;
		}

		int i = 0;
		int j = nums.size() - 1;

		// Search for the left one
		while (i < j)
		{
			int mid = (i + j) / 2;
			if (nums[mid] < target)
				i = mid + 1;
			else 
				j = mid;
		}

		if (nums[i] != target)
			return ret;
		else
			ret[0] = i;

		// Search for the right one
		j = nums.size() - 1;  // We don't have to set i to 0 the second time.

		while (i < j)
		{
			int mid = (i + j) / 2 + 1;	// Make mid biased to the right

			if (nums[mid] > target)
				j = mid - 1;
			else 
				i = mid;				// So that this won't make the search range stuck.
		}
		ret[1] = j;

		return ret;
    }
};


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {

		int l = 0;
		int r = nums.size() - 1;

		vector<int> ret = { -1, -1 };

		while (l <= r)
		{
			int mid = (l + r) / 2;

			if (target == nums[mid])
			{
				int i = 1;
				while (0 <= mid - i && nums[mid] == nums[mid - i]) i++;
				ret[0] = mid - i + 1;

				i = 1;
				while (mid + i < nums.size() && nums[mid] == nums[mid + i]) i++;
				ret[1] = mid + i - 1;

				break;
			}

			if (nums[l] <= target && target <= nums[mid])
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}

		return ret;
	}
};
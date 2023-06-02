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

//refer to solution APPROACH 1 USING BINARY SEARCH
https://leetcode.com/problems/find-the-duplicate-number/solutions/1892872/c-algorithm-4-approaches-binary-search-brute-force-cnt-array-map/
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int low = 1, high = nums.size() - 1, cnt;

		while (low <= high)
		{
			int mid = low + (high - low) / 2;
			cnt = 0;
			// cnt number less than equal to mid
			for (int n : nums)
			{
				if (n <= mid)
					++cnt;
			}
			// binary search on left
			if (cnt <= mid)
				low = mid + 1;
			else
				// binary search on right
				high = mid - 1;

		}
		return low;
	}
	// for github repository link go to my profile.

};
//9 Approaches: Count, Hash, In - place Marked, Sort, Binary Search, Bit Mask, Fast Slow Pointers
https://leetcode.com/problems/find-the-duplicate-number/solutions/1892921/9-approaches-count-hash-in-place-marked-sort-binary-search-bit-mask-fast-slow-pointers/
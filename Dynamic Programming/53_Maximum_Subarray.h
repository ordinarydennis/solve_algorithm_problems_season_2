class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		int ret = INT_MIN;

		for (int l = 1; l <= nums.size(); l++)
		{
			for (int i = 0; i <= nums.size() - l; i++)
			{
				int sum = std::accumulate(nums.begin() + i, nums.begin() + i + l, 0);

				ret = std::max(ret, sum);
			}
		}

		return ret;
	}
};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		int ret = INT_MIN;

		vector<vector<int>> mat(nums.size(), vector<int>(nums.size()));

		for (int i = 0; i < nums.size(); i++)
		{
			mat[i][0] = nums[i];
			ret = std::max(ret, mat[i][0]);
		}

		for (int l = 1; l <= nums.size(); l++)
		{
			for (int i = 0; i < nums.size() - l; i++)
			{
				mat[i][l] = mat[i][l - 1] + nums[i + l];
				ret = std::max(ret, mat[i][l]);
			}
		}

		return ret;
	}
};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		int max = INT_MIN, curSum = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			curSum += nums[i];

			max = std::max(max, curSum);

			if (curSum < 0) curSum = 0;
		}

		return max;
	}
};


class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		int max = 0;
		int curSum = 0;

		int curEnd = 0;
		int curStart = 0;

		int start = curStart;
		int end = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (curSum < 0)
			{
				start = curStart;
				end = curEnd;
				curStart = i;
			}

			curSum += nums[i];

			if (max < curSum)
			{
				curEnd = i;
			}
		}
	}
};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int globalMaxSum = nums[0], currMaxSum = nums[0];
		int globalStart = 0, globalEnd = 0, currStart = 0;
		for (int ind = 1; ind < nums.size(); ind++) {
			if (currMaxSum < 0)    // same as: currMaxSum + nums[ind] < nums[ind]
				currMaxSum = nums[ind], currStart = ind;
			else 
				currMaxSum += nums[ind];

			// use only below if cond. to find anyone of all subArrays with globalMaxSum
			if (globalMaxSum < currMaxSum)
				globalMaxSum = currMaxSum, globalStart = currStart, globalEnd = ind;
			// use below to find anyone of all maxLen subArrays with globalMaxSum
			else if (globalMaxSum == currMaxSum and globalEnd - globalStart < ind - currStart)
				globalStart = currStart, globalEnd = ind;
		}
		cout << "Following SubArray has maxSum: " << globalMaxSum;
		cout << " and has length: " << globalEnd - globalStart + 1 << " :\n";
		printSubArray(nums, globalStart, globalEnd);

		return globalMaxSum;
	}
	void printSubArray(vector<int>& nums, int low, int high) {
		for (int ind = low; ind <= high; ind++)
			cout << nums[ind] << " ";
		cout << "\n";
	}
};

//https://leetcode.com/problems/maximum-subarray/solutions/1470547/c-easy-clean-solution-fastest-0ms-all-methods-follow-ups-detailed-explanation/

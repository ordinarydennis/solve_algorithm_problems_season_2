class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {

		double ret = INT_MIN;
		double sum = 0; 

		for (int i = 0; i < nums.size(); i++)
		{
			if (i < k)
			{
				sum += nums[i];
			}
			else
			{
				ret = std::max(sum, ret);
				sum += nums[i] - nums[i - k];
			}
		}

		ret = std::max(ret, sum);

		return ret / k;
	}
};


//C++ simple sliding-window solution
//leetcode.com/problems/maximum-average-subarray-i/solutions/105428/c-simple-sliding-window-solution/
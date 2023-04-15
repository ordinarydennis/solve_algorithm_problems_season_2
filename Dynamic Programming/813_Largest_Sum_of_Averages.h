class Solution {

	double sumOfNums(vector<int>& nums, int startIndex, int count, int k)
	{
		if (k == count)
		{
			double sum = std::accumulate(nums.begin() + startIndex, nums.end(), 0);
			double dsum = sum / (nums.size() - startIndex);
			return dsum;
		}

		double max = 0;

		for (int i = startIndex; i < nums.size() - (k - count); i++)
		{
			double sum = std::accumulate(nums.begin() + startIndex, nums.begin() + startIndex + (i - startIndex) + 1, 0);

			double dsum = sum / ((i - startIndex) + 1);

			double dSumNum = sumOfNums(nums, i + 1, count + 1, k);

			max = std::max(max, dsum + dSumNum);
		}

		return max;
	}

public:
	double largestSumOfAverages(vector<int>& nums, int k) {

		return sumOfNums(nums, 0, 1, k);

	}
};
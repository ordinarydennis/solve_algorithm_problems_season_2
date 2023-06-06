class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {


		int l = 0;
	
		double sum = 0;

		while (l + k < nums.size())
		{
			double sum2 = std::accumulate(nums.begin() + l, nums.begin() + l + k + 1, 0);
			sum = std::max(sum2, sum);
			l++;
		}

		return sum / k;

	}
};
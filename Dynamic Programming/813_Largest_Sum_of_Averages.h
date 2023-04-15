class Solution {

	double sumOfNums(vector<int>& nums, int startIndex, int count, int k)
	{
		if (k == count)
		{
			int sum = std::accumulate(nums.begin() + startIndex, nums.end(), 0);
			double dsum = sum / (nums.size() - startIndex);
			return dsum;
		}

		double max = 0;

		for (int i = startIndex; i <= nums.size() - k; i++)
		{
			int sum = std::accumulate(nums.begin() + startIndex, nums.begin() + startIndex + i + 1, 0);

			double dsum = sum / (i + 1);

			double dSumNum = sumOfNums(nums, i + 1, count + 1, k);

			max = std::max(max , dsum + dSumNum);
		}

		return max;
	}

public:
	double largestSumOfAverages(vector<int>& nums, int k) {

		return sumOfNums(nums, 0, 1, k);

	}
};


class Solution {
	public double largestSumOfAverages(int[] A, int K)
	{
		int[] sum = new int[A.length];

		for (int i = 0; i < A.length; i++) 
			sum[i] = A[i] + (i > 0 ? sum[i - 1] : 0);

		return h(A, K, sum, A.length, 0);
	}

	public double h(int[] A, int k, int[] sum, int len, int s)
	{
		if (k == 1)
			return ((double)(sum[len - 1] - sum[s] + A[s]) / (len - s));

		double num = 0;
		
		for (int i = s; i + k <= len; i++)
		{
			num = Math.max(num, 
				((double)(sum[i] - sum[s] + A[s]) / (i - s + 1)) + 
				h(A, k - 1, sum, len, i + 1)
			);
		}
		return num;
	}
}
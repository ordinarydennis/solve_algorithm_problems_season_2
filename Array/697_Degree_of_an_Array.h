class Solution {
public:
	int findShortestSubArray(vector<int>& A) {

		int degree = 0;

		std::unordered_map<int, int> count;
		std::unordered_map<int, int> start;

		int ret = INT_MAX;

		for (int i = 0; i < A.size(); i++)
		{
			int n = A[i];

			count[n]++;

			if (1 == count[n])
			{
				start[n] = i;
			}

			if (degree < count[n])
			{
				degree = count[n];
				ret = i - start[n] + 1;
			}
			else
			{
				if (1 < count[n])
				{
					ret = std::min(ret, i - start[n] + 1);
				}
			}
		}

		return ret;
	}
};

// solution https://leetcode.com/problems/degree-of-an-array/solutions/124317/java-c-python-one-pass-solution/
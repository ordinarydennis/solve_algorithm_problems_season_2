
//Approach 1: Brute Force with Set
class Solution {

public:
	int lenLongestFibSubseq(vector<int>& arr) {

		std::unordered_set<int> m(arr.begin(), arr.end());

		int ret = 0;

		for (int a = 0; a < arr.size(); a++)
		{
			for (int b = a + 1; b < arr.size() - 1; b++)
			{
				int n1 = arr[a];
				int n2 = arr[b];
				int f = n1 + n2;

				int count = 0;

				while (m.count(f))
				{
					n1 = n2;
					n2 = f;
					f = n1 + n2;

					count++;
				}

				ret = std::max(ret, count);
			}
		}

		
		return 0 == ret ? 0 : ret + 2;
	}
};

//https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/editorial/


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

class Solution {
public:
	int lenLongestFibSubseq(vector<int>& A) {
		int N = A.size();
		
		unordered_map<int, int> index;

		for (int i = 0; i < N; ++i)
			index[A[i]] = i;

		unordered_map<int, int> longest;

		int ans = 0;

		for (int k = 0; k < N; ++k)
		{
			for (int j = 0; j < k; ++j) {

				if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
					int i = index[A[k] - A[j]];
					longest[j * N + k] = longest[i * N + j] + 1;
					ans = max(ans, longest[j * N + k] + 2);
				}

			}
		}


		return ans >= 3 ? ans : 0;
	}
};



//https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/editorial/

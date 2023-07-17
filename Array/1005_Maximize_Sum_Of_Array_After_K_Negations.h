class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		for (int i = 0; K > 0 && i < A.size() && A[i] < 0; ++i, --K)
			A[i] = -A[i];
		return accumulate(A.begin(), A.end(), 0) - (K % 2) * *min_element(A.begin(), A.end()) * 2;
	}
};


//read solution
//leetcode.com/problems/maximize-sum-of-array-after-k-negations/solutions/252254/java-c-python-sort/

class Solution {
public:
	bool isMonotonic(vector<int> A) {

		bool inc = true;
		bool dec = true;

		for (int i = 1; i < A.size(); i++)
		{
			inc &= A[i - 1] <= A[i];

			dec &= A[i - 1] >= A[i];

			if (!inc && !dec)
				return false;
		}
			

		return inc || dec;
	}
};

//https://leetcode.com/problems/monotonic-array/solutions/165889/c-java-python-one-pass-o-n/
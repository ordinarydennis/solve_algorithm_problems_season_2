class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {

		int sum = std::accumulate(A.begin(), A.end(), 0);

		if (sum % 3 != 0)
		{
			return false;
		}

		int average = sum / 3;

		int l = 0, r = A.size() - 1;

		int leftSum = A[l++], rightSum = A[r--];

		do
		{
			if (leftSum != average)
				leftSum += A[l++];

			if (l < r && rightSum != average)
				rightSum += A[r--];

			if (l <= r && leftSum == average && rightSum == average)
				return true;

		} while (l < r);


		return false;
	}
};

//there is no correct answer in leetcode.
//if the input value is sorted, every answer is not passed.
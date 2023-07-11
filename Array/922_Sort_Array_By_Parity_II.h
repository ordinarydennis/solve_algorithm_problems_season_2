//my solution
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {

		for (int i = 0, j = 1; i < A.size(); i += 2, j += 2)
		{
			while (i < A.size() && A[i] % 2 == 0)
				i += 2;

			while (j < A.size() && A[j] % 2 == 1)
				j += 2;

			if (i < A.size())
				swap(A[i], A[j]);
		}
		return A;
	}

};

//solution
//https://leetcode.com/problems/sort-array-by-parity-ii/solutions/181158/c-5-lines-two-pointers-2-liner-bonus/
vector<int> sortArrayByParityII(vector<int>& A) {

	for (int i = 0, j = 1; i < A.size(); i += 2, j += 2)
	{
		while (i < A.size() && A[i] % 2 == 0) 
			i += 2;

		while (j < A.size() && A[j] % 2 == 1)
			j += 2;

		//i´Â Â¦¼öÁö¸¸ È¦¼ö°¡ ³ª¿Â ÀÎµ¦½º
		//j´Â È¦¼öÁö¸¸ Â¦¼ö°¡ ³ª¿Â ÀÎµ¦½º
		//µÑÀÌ Ä¡È¯
		if (i < A.size()) 
			swap(A[i], A[j]);
	}
	return A;
}

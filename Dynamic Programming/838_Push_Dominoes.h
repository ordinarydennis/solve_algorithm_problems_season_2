class Solution {
public:
	string pushDominoes(string s) {

		int right = -1;
		int end = s.size();

		for (int i = 0; i < end; i++)
		{
			if ('L' == s[i])
			{
				if (right == -1)
				{
					for (int L = i - 1; 0 < L && s[L] == '.'; L--)
					{
						s[L] = 'L';
					}
				}
				else
				{
					for (int L = i - 1, R = right + 1; s[L] == '.' && R < L; L--, R++)
					{
						s[L] = 'L';
						s[R] = 'R';
					}
					right = -1;
				}
			}
			else if ('R' == s[i])
			{
				if (right != -1)
				{
					for (int R = right + 1; R < i; R++)
					{
						s[R] = 'R';
					}
				}
				right = i;
			}
		}

		if (-1 != right)
		{
			for (int R = right + 1; R < end; R++)
			{
				s[R] = 'R';
			}
		}


		return s;
	}
};

//https://leetcode.com/problems/push-dominoes/solutions/132332/java-c-python-two-pointers/
class Solution {
public:
	string longestPalindrome(string s) {

		vector<vector<int>> mat(s.size(), vector<int>(s.size()));

		int begin = 0;
		int max = 0;

		for (int i = 0; i < s.size(); i++)
		{
			mat[i][i] = 1;
		}

		for (int a = 0; a < s.size() - 2; a++)
		{
			for (int b = a + 1; b < s.size(); b++)
			{
				if (s[a] != s[b])
				{
					continue;
				}

				if (1 == mat[a + 1][b - 1])
				{
					mat[a][b] = 1;

					if (max < b - a)
					{
						max = b - a;
						begin = a;
					}
				}
				
			}
		}

		return s.substr(begin, max + 1);

	}
};
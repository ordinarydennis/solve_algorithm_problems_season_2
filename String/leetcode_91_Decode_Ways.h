class Solution {

	int dfs(string& s, int i)
	{
		if (s.size() == i)
		{
			return 1;
		}

		if ('0' == s[i])
		{
			return 0;
		}

		if (s.size() - 1 == i)
		{
			return 1;
		}

		string sub = s.substr(i, 2);

		int way1 = dfs(s, i + 1);
		int way2 = 0;
		if (0 < stoi(sub) && stoi(sub) <= 26)
		{
			way2 = dfs(s, i + 2);
		}

		return way1 + way2;
	}


public:
	int numDecodings(string s) {

		return dfs(s, 0);

	}
};


//https://leetcode.com/problems/decode-ways/solutions/740182/c-recursion-recursion-with-memoization-dp-explained/
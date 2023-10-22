// first approach brute force
class Solution {

	bool isPalindrome(const auto& str, int s, int e)
	{
		while (s < e)
		{
			if (str[s] != str[e])
			{
				return false;
			}

			s++;
			e--;
		}

		return true;
	}

public:
	string longestPalindrome(string s) {

		if (1 == s.size())
		{
			return s;
		}

		string ret;

		int max = 0;

		for (int a = 0; a < s.size() - 1; a++)
		{
			for (int b = a + 1; b < s.size(); b++)
			{
				if (isPalindrome(s, a, b))
				{
					if (max < b - a)
					{
						max = b - a;
						ret = s.substr(a, b - a + 1);
					}
				}
			}
		}

		string rr;
		rr += s[0];

		return (0 == ret.size()) ? rr : ret;
	}
};


//second approach dp
class Solution {

	bool isPalindrome(std::vector<vector<bool>>& memo, string& str, int s, int e)
	{
		if (s == e)
		{
			return memo[s][e] = true;
		}

		if (1 == (e - s))
		{
			if (str[s] == str[e])
			{
				return memo[s][e] = true;
			}
			else
			{
				return memo[s][e] = false;
			}
		}

		if (str[s] == str[e])
		{
			if (memo[s + 1][e - 1])
			{
				return memo[s][e] = true;
			}
			else
			{
				return memo[s][e] = false;
			}
		}

		return false;
	}

public:
	string longestPalindrome(string s) {

		int len = static_cast<int>(s.size());

		std::vector<vector<bool>> memo(len, vector<bool>(len, false));

		
		int max = 0;
		int index = 0;

		for (int a = 0; a < len; a++)
		{
			for (int b = 0, c = a, c < len; b++, c++)
			{
				if (isPalindrome(memo, s, b, c))
				{
					if (max < (c - b))
					{
						index = b;
						max = c - b;
					}
				}
			}
		}

		return s.substr(index, max);
	}
};



//https://leetcode.com/problems/longest-palindromic-substring/solutions/3202985/best-c-3-solution-dp-string-brute-force-optimize-one-stop-solution/

class Solution {

	bool isPalindrome(vector<vector<bool>>& dp, string& s, int start, int end)
	{
		if (start == end) 
			return dp[start][end] = true;

		if (1 == end - start) 
			return dp[start][end] = s[start] == s[end];
			
		if (s[start] == s[end] && dp[start + 1][end - 1]) 
			return dp[start][end] = true;
		
		return false;
	}


public:
	string longestPalindrome(string s) {

		int len = static_cast<int>(s.size());

		vector<vector<bool>> dp(len, vector<bool>(len, false));

		int max = 0;
		int index = 0;

		for (int a = 0; a < len; a++)
		{
			for (int b = 0, c = a; c < len; b++, c++)
			{
				if (false == isPalindrome(dp, s, b, c))
					continue;

				if (max < c - b + 1)
				{
					index = b;
					max = c - b + 1;
				}	
			}
		}

		return s.substr(index, max);
	}
};
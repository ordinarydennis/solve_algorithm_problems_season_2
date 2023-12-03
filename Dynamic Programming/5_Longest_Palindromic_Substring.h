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

class Solution {

	bool isPalindrome(string& s, int left, int right)
	{
		while (left < right && s[left] == s[right])
		{
			left++;
			right--;
		}

		return s[left] == s[right];
	}

public:
	string longestPalindrome(string s) {

		for (int length = s.size(); 0 < length; length--)
		{
			for (int start = 0; start <= s.size() - length; start++)
			{
				if (isPalindrome(s, start, start + length - 1))
				{
					return s.substr(start, length);
				}
			}
		}

		return "";
	}
};
//Time complexity: O(n^3)
//Space complexity: O(1)

//https://leetcode.com/problems/longest-palindromic-substring/editorial/


class Solution {

public:
	string longestPalindrome(string s) {

		std::vector<std::vector<bool>> mat(s.size(), std::vector<bool>(s.size()));
		
		int start = 0;
		int length = 1;

		for (int i = 0; i < s.size(); i++)
		{
			mat[i][i] = true;
			if (i < s.size() - 1 && s[i] == s[i + 1])
			{
				mat[i][i + 1] = true;
				start = i;
				length = 2;
			}
		}
			

		for (int l = 3; l <= s.size(); l++)
		{
			for (int i = 0; i <= s.size() - l; i++)
			{
				int right = i + l - 1;

				if (s[i] == s[right] && mat[i + 1][right - 1])
				{
					mat[i][right] = true;
					start = i;
					length = l;
				}
			}
		}

		return s.substr(start, length);
	}
};

//Time complexity: O(n^2)
//Space complexity: O(n^2)



class Solution {
public:
	string longestPalindrome(string s) {

		vector<vector<bool>> mat(s.size(), vector<bool>(s.size()));

		int start = 0;
		int length = 1;

		for (int i = 0; i < s.size(); i++)
		{
			mat[i][i] = true;
			if (i < s.size() - 1 && s[i] == s[i + 1])
			{
				mat[i][i + 1] = true;
				start = i;
				length = 2;
			}
		}

		for (int l = 3; l <= s.size(); l++)
		{
			for (int i = 0; i <= s.size() - l; i++)
			{
				int right = i + l - 1;
				if (s[i] == s[right] && mat[i + 1][right - 1])
				{
					mat[i][right] = true;
					start = i;
					length = l;
				}
			}
		}

		return s.substr(start, length);
	}
};

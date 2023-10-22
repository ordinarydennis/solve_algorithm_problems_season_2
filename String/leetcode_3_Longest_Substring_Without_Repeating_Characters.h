//first approach brute force
class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		int ret = 0;

		for (int a = 0; a < s.size(); a ++)
		{
			string str;

			for (int b = a; b < s.size(); b++)
			{
				auto f = str.find(s[b]);

				if (f == string::npos)
				{
					str += s[b];
				}
				else
				{
					break;
				}
			}

			ret = std::max(ret, str.size());
			
		}

		return ret;
	}
};


class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		int start = -1;

		int ret = 0;

		std::unordered_map<char, int> memo;

		for (int i = 0; i < s.size(); i++)
		{
			const auto& it = memo.find(s[i]);

			if (memo.end() != it)
			{
				if (start < memo[s[i]])
				{
					start = memo[s[i]];
				}
			}

			memo[s[i]] = i;

			ret = std::max(ret, i - start);
		}

		return ret;
	}

};

//if you encounter same value, the start point is updated to previous point 
//you need to change the starting point to new point to avoid duplication. 
//ex "abba"


class Solution {
public:
	int lengthOfLongestSubstring(string s) {


		std::unordered_map<char, int> memo;

		int max = static_cast<int>(s.size());

		int start = -1;

		int ret = 0;

		for (int i = 0; i < max; i++)
		{
			const auto& it = memo.find(s[i]);

			if (memo.end() != it)
			{
				if (start < it->second)
				{
					start = it->second;
				}	
			}

			memo[s[i]] = i;

			ret = std::max(ret, i - start);
		}


		return ret;
	}
};


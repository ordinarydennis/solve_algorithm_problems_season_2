class Solution {
public:
	string countAndSay(int n) {

		if (1 == n) return "1";
		if (2 == n) return "11";

		string ret = "11";

		int count = 1;

		for (int a = 3; a <= n; a++)
		{
			string s;

			for (int b = 1; b <= ret.size(); b++)
			{
				if (ret[b] == ret[b - 1])
				{
					count++;
					continue;
				}

				s += '0' + count;
				s += ret[b - 1];
				count = 1;
			}

			ret = std::move(s);
		}

		return ret;
	}
};

//https://leetcode.com/problems/count-and-say/solutions/2716207/c-easy-detailed-explaination-optimized/


class Solution {
public:
	string countAndSay(int n) {

		if (1 == n)
			return "1";
		if (2 == n)
			return "11";
		
		
		int n2 = 3;
		string s = "11";

		while (n2 <= n)
		{
			int count = 1;

			string str;

			for (int i = 1; i <= s.size(); i++)
			{
				if (i < s.size() && s[i] == s[i - 1])
				{
					count++;
				}
				else
				{
					str += to_string(count);
					str += s[i - 1];
					count = 1;
				}
			}

			n2++;
			s = str;
		}

		return s;
	}
};

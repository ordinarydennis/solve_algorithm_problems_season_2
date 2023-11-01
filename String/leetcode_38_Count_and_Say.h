class Solution {
public:
	string countAndSay(int n) {

		std::vector<string> m(n + 5, "");

		m[1] = "1";
		m[2] = "11";
		m[3] = "21";
		m[4] = "1211";

		if (n <= 4)
		{
			return m[n];
		}

		string& s = m[n - 1];

		char p = s[0];
		int count = 1;

		string ret;

		for (int i = 1; i <= s.size(); i++)
		{
			if (i < s.size() && p == s[i])
			{
				count++;
			}
			else
			{
				ret += '0' + count;
				ret += p;

				if (i < s.size())
				{
					p = s[i];
					count = 1;
				}
			}
		}

		return ret;
	}
};
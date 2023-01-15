class Solution {

public:
	string removeKdigits(string num, int k) {

		string ret;

		for (char c : num)
		{
			while (ret.size() && c < ret.back() && k)
			{
				ret.pop_back();
				k--;
			}

			if (ret.empty() && '0' == c)
				continue;

			ret.push_back(c);
		}

		while (k && ret.size())
		{
			ret.pop_back();
			k--;
		}

		return ret.empty() ? "0" : ret;
	}
};
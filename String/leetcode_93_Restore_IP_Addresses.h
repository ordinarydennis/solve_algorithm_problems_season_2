class Solution {

	vector<string> ret;

	void dfs(string& s, string str, int index, int count)
	{
		if (4 < count)
		{
			return;
		}

		for (int i = 3; 1 <= i; i--)
		{

			if (s.size() < index + i)
			{
				continue;
			}

			if ('0' == s[index])
			{
				continue;
			}

			string sub = s.substr(index, i);

			if (255 < stoi(sub))
			{
				continue;
			}

			if (count == 4)
			{
				if (index + i == s.size() - 1)
				{
					ret.push_back(str + sub);
				}

				return;
			}

			dfs(s, str + sub + ".", index + i, count + 1);
		}
	}


public:
	vector<string> restoreIpAddresses(string s) {

		dfs(s, "", 0, 1);

		return ret;

	}
};
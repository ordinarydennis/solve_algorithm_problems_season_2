class Solution {

	vector<int> dfs(string s, int i)
	{
		if (s.size() <= i)
			return {};

		const auto& list = dfs(s, i + 1);

		for (int n : list)
		{
			int num = s[i] * 10 + n;

			if (26 < num)
			{
				continue;
			}

			list.push_back(num);
		}

		list.push_back(s[i]);

		return list;
	}


public:
	int numDecodings(string s) {

		return dfs(s, 0);

	}
};

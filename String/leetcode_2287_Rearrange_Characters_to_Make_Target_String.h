class Solution {
public:
	int rearrangeCharacters(string s, string target) {

		if (s.size() < target.size())
		{
			return 0;
		}

		std::unordered_map<char, int> m;

		for (char c : s)
		{
			m[c]++;
		}

		int ret = 0;

		while (m.size())
		{
			int i = 0;

			for (i = 0; i < target.size(); i++)
			{
				char c = target[i];

				auto it = m.find(c);
				if (m.end() == it)
				{
					return 0;
				}

				m[c]--;

				if (0 == m[c])
				{
					if (i < target.size())
					{
						return ret;
					}
					else
					{
						return ++ret;
					}
				}
			}

			ret++;

		}
		
		return ret;
	}
};
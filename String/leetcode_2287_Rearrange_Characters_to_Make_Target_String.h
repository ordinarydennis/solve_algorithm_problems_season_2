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

		while (true)
		{
			int i = 0;

			for (; i < target.size(); i++)
			{
				char c = target[i];

				//because map int default value is 0, if it is zero, it means no characters..
				if (0 < m[c])
				{
					m[c]--;
				}
				else
				{
					break;
				}
			}

			//If index i does not reach the end of the target string, it means that the target string is not satisfied.
			if (i == target.size())
			{
				ret++;
			}
			else
			{
				break;
			}
		}

		return ret;
	}
};
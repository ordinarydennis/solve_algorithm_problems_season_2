class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {

		std::unordered_map<int, int> m;

		for (int i = 0; i < order.size(); i++)
		{
			m[order[i]] = i;
		}

		for (int i = 0; i < words.size() - 1; i++)
		{
			auto s1 = words[i];
			auto s2 = words[i + 1];

			int len = std::min(s1.size(), s2.size());

			int a = 0;

			for (; a < len; a++)
			{
				if (m[s2[a]] < m[s1[a]])
				{
					break;
				}
			}

			if (len <= a && s2.size() < s1.size())
			{
				return false;
			}


			if (a <= len)
			{
				return true;
			}
		}

		return true;
	}
};
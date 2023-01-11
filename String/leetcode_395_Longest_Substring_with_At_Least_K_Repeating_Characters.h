class Solution {
public:
	int longestSubstring(string s, int k) {

		std::unordered_map<char, int> m1;

		std::unordered_map<char, int> m2;

		for (int i = 0; i < s.size(); i++)
		{
			auto it = m1.find(s[i]);

			if (m1.end() == it)
			{
				m1.emplace(s[i], 1);

				if (1 == k)
				{
					m2[s[i]] = 1;
				}
			}
			else
			{
				it->second++;

				if (k <= it->second)
				{
					m2[it->first] = it->second;
				}
			}

		}

		int ret = INT_MIN;

		for (int i = 0; i < s.size(); i++)
		{
			string str;

			std::unordered_map<char, int> m3;

			for (int a = i + 0; a < s.size(); a++)
			{
				auto it = m2.find(s[a]);

				if (m2.end() == it)
				{
					break;
				}

				str += s[a];

				auto it2 = m3.find(s[a]);

				if (m3.end() == it2)
				{
					m3.emplace(s[i], 1);
				}
				else
				{
					it2->second++;
				}
			}

			bool isFound = true;
			for (char c : str)
			{
				auto it4 = m3.find(c);
				if (m3.end() == it4 || it4->second < k)
				{
					isFound = false;
				}
			}

			if (isFound)
			{
				ret = std::max(ret, static_cast<int>(str.size()));
			}
		}

		return ret;

	}
};
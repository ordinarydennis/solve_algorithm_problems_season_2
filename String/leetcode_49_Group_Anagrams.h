class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		std::unordered_map<int, vector<string>> m;

		for (const auto& s : strs)
		{
			int num = 0;
			for (int i = 0; i < s.size(); i++)
			{
				short n = s[i] - 'a';

				num += 1 << n;
			}
			m[num].push_back(s);
		}

		vector<vector<string>> ret;

		for (auto& [_, list] : m)
		{
			ret.push_back(std::move(list));

		}

		return ret;
	}
};

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		std::unordered_map<string, vector<string>> m;

		for (const auto& s : strs)
		{
			string s2 = s;

			std::sort(s2.begin(), s2.end());

			m[s2].push_back(s);
		}

		vector<vector<string>> ret;

		for (auto& [_, list] : m)
		{
			ret.push_back(std::move(list));

		}

		return ret;
	}
};
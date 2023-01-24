class Solution {

public:
	string frequencySort(string s) {

		std::map<char, int> hash;

		for (char c : s)
		{
			hash[c]++;
		}

		std::vector<pair<char, int>> pairList(hash.begin(), hash.end());

		std::sort(pairList.begin(), pairList.end(), [](pair<char, int>& a, pair<char, int>& b) {

			return a.second != b.second ? a.second > b.second : a.first < b.first;
		
			}
		
		);

		string ret;

		for (const auto& [c, size] : pairList)
		{
			for (int i = 0; i < size; i++)
			{
				ret.push_back(c);
			}
		}

		return ret;
	}
};
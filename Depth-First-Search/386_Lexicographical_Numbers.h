class Solution {
public:
	vector<int> lexicalOrder(int n) {

		vector<string> sList;

		sList.reserve(n);

		for (int i = 1; i <= n; i++)
		{
			sList.emplace_back(std::move(to_string(i)));
		}

		std::sort(sList.begin(), sList.end());

		vector<int> ret;

		ret.reserve(sList.size());

		for (const auto& s : sList)
		{
			ret.push_back(stoi(s));
		}

		return ret;
	}
};
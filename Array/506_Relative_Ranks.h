class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& score) {

		std::map<int, int, std::greater<int>> m;

		for (int i = 0; i < score.size(); i++)
		{
			m.emplace(score[i], i);
		}


		vector<string> ret(score.size(), "");

		int i = 1;

		for (auto [score, index] : m)
		{
			if (1 == i)
			{
				ret[index] = "Gold Medal";
			}
			else if (2 == i)
			{
				ret[index] = "Silver Medal";
			}
			else if (3 == i)
			{
				ret[index] = "Bronze Medal";
			}
			else
			{
				ret[index] = to_string(i);
			}

			i++;
		}

		return ret;
	}
};
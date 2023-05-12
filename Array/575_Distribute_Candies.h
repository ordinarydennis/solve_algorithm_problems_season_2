class Solution {
public:
	int distributeCandies(vector<int>& candyType) {

		std::set<int> s;

		for (int i = 0; i < candyType.size(); i++)
		{
			s.insert(candyType[i]);
		}

		return std::min(static_cast<int>(s.size()), static_cast<int>(candyType.size() / 2));
	}
};
class Solution {
public:
	bool digitCount(string num) {

		std::unordered_map<char, int> m;

		for (char c : num)
		{
			m[c]++;
		}

		for (int i = 0; i < num.size(); i++)
		{
			auto it = m.find('0' + i);

			int count = 0;

			if (m.end() != it)
			{
				count = it->second;
			}

			if (count + '0' != num[i])
			{
				return false;
			}
		}

		return true;
	}
};
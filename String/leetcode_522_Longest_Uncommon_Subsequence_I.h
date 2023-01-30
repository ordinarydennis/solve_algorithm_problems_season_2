class Solution {
public:
	int findLUSlength(string a, string b) {

		string sLong;
		string sShort;


		if (a.size() < b.size())
		{
			sLong = b;
			sShort = a;
		}
		else
		{
			sShort = b;
			sLong = a;
		}

		int count = 0;

		for (char c1 : sLong)
		{
			if (std::count(sShort.begin(), sShort.end(), c1))
			{
				count++;
			}
		}

		return (count == sLong.size()) ? -1 : sLong.size() - count;

	}
};
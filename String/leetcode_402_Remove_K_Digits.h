class Solution {

	int mMin = INT_MAX;
	int mK = 0;

	void removeStr(string s, int k)
	{
		if (mK == k)
		{
			mMin = std::min(mMin, std::atoi(s.c_str()));
			return;
		}

		for (int i = 0; i < s.size() - mK - k; i++)
		{
			removeStr(s.substr(i, 1), k + 1);
		}
	}

public:
	string removeKdigits(string num, int k) {

		mK = k;

		num.size() - k;

		removeStr(num, 0);

		return std::to_string(mMin);
	}
};

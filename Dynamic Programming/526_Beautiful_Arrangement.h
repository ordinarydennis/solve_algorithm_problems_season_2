class Solution {

	int mRet = 0;

	bool check(int n, vector<int>& list)
	{
		if (list.size() <= n)
		{
			return isBeautiful(list);
		}

		for (int i = n; i < list.size(); i++)
		{
			list.push_back(i);

			if (check(i + 1, list))
			{
				mRet++;
			}

			list.pop_back();
		}

		return false;
	}

	bool isBeautiful(vector<int>& list)
	{
		for (int i = 1; i < list.size(); i++)
		{
			if (list[i] % i != 0 && i % list[i] != 0)
			{
				return false;
			}
		}

		return true;
	}

public:
	int countArrangement(int n) {

		vector<int> list(n + 1, 0);

		check(1, list);

		return mRet;
	}
};
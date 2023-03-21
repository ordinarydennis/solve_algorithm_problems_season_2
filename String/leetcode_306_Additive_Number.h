class Solution {

	void check(const string& num, int begin, int end, int sum, int count)
	{

		for (int i = 1, i < num.size(); i++)
		{
			string s = num.substr(begin, i);
			
			int n = std::stoi(s);

			if (2 == count)
			{
				if (sum == n)
				{
					check(num, begin + 1, end, sum + n, count + 1);
				}
				else
				{

				}
			}
			else
			{
				check(num, begin + 1, end, sum + n, count + 1);
			}
		}

	}

public:
	bool isAdditiveNumber(string num) {


		return check(num, 0, num.size(), 0, 0);


	}
};
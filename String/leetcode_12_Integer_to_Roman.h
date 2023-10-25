class Solution {
public:
	string intToRoman(int num) {

		int r = num;

		vector<string> strList;

		int de = 1;

		while (r)
		{
			int n = r % 10;

			n *= de;

			string str;

			if (0 == n || 10 == n)
			{
				str += "X";
			}
			else if (5 == n)
			{
				str += "V";
			}
			else if (4 == n)
			{
				str += "IV";
			}
			else if (9 == n)
			{
				str += "IX";
			}
			else if (n < 4)
			{
				for (int i = 0; i < n; i++)
				{
					str += "I";
				}
			}
			else if (n < 9)
			{
				str += "V";
				for (int i = 0; i < n - 5; i++)
				{
					str += "I";
				}
			}
			else if (n == 50)
			{
				str += "L";
			}
			else if (n == 90)
			{
				str += "XC";
			}
			else if (n == 900)
			{
				str += "CM";
			}
			else if (n == 1000)
			{
				str += "M";
			}

			strList.push_back(str);

			r = r / 10;

			de *= 10;
		}


		int len = strList.size();

		string ret;

		for (int i = len - 1; i >= 0; i--)
		{
			ret += strList[i];
		}

		return ret;
	}
};
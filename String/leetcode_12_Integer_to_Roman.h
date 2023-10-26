class Solution {
public:
	string intToRoman(int num) {

		vector<pair<int, string>>  clist = {
			{1000, "M"},
			{900, "CM"},
			{500, "D"},
			{400, "CD"},
			{100, "C"},
			{90, "XC"},
			{50, "L"},
			{40, "XL"},
			{10, "X"},
			{9, "IX"},
			{5, "V"},
			{4, "IV"},
			{1, "I"}
		};

		string ret;

		for (int i = 0; i < clist.size(); i++)
		{
			while (num >= clist[i].first)
			{
				ret += clist[i].second;
				num -= clist[i].first;
			}
		}

		return ret;
	}
};

//https://leetcode.com/problems/integer-to-roman/solutions/3216797/easiest-beginner-friendly-sol-c-java-python/

//first approach
class Solution {
public:
	string convert(string s, int numRows) {

		vector<vector<char>> m(numRows + 1, vector<char>(s.size() + 1, ' '));


		int dir = 0;

		int x = 0;
		int y = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (0 == dir)
			{
				if (y + 1 <= numRows)
				{
					y++;
				}
				else
				{
					dir = 1;
					y--;
					x++;
				}
			}
			else if (1 == dir)
			{
				if (y - 1 < 0)
				{
					dir = 0;
					y++;
				}
				else
				{
					y--;
					x++;
				}
			}

			m[y][x] = s[i];
		}

		string ret;

		for (int a = 1; a <= numRows; a++)
		{
			for (int b = 0; b <= s.size(); b++)
			{
				if (' ' != m[a][b])
				{
					ret += m[a][b];
				}
			}
		}

		return ret;
	}
};

//second approach
class Solution {
public:
	string convert(string s, int numRows) {

		if (numRows <= 1) return s;

		std::vector<string> slist(numRows, "");

		int p = 0;
		int dir = 1;

		for (int i = 0; i < s.size(); i++)
		{
			if (p == 0 || p == numRows - 1) dir *= -1;

			slist[p] += s[i];

			if (-1 == dir) p++;
			else p--;
		}

		string ret;

		for (auto& str : slist)
			ret += std::move(str);

		return ret;
	}
};

//https://leetcode.com/problems/zigzag-conversion/solutions/3134053/c-faster-than-95-easy-understanding-clean-concise-code/

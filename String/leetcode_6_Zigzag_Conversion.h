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
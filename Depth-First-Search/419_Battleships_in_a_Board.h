class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {

		int maxY = board.size();
		int maxX = board[0].size();

		int ret = 0;
		
		for (int y = 0; y < maxY; y++)
		{
			for (int x = 0; x < maxX; x++)
			{
				if ('.' == board[y][x])
					continue;

				if (0 < y && 'X' == board[y - 1][x])
					continue;

				if (0 < x && 'X' == board[y][x - 1])
					continue;

				ret++;
			}
		}

		return ret;
	}
};
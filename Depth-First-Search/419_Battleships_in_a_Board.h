class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {

		int ret = 0;

		for (int y = 0; y < board.size(); y++)
		{
			for (int x = 0; x < board[0].size(); x++)
			{
				if ('.' == board[y][x])
				{
					continue;
				}

				if (0 < y && 'X' == board[y - 1][x])
				{
					continue;
				}

				if (0 < x && 'X' == board[y][x - 1])
				{
					continue;
				}
				
				ret++;

			}
		}

		return ret;
	}
};

//https://leetcode.com/problems/battleships-in-a-board/solutions/90909/c-3ms-6-lines-solution-with-runtime-o-n-and-space-o-1/
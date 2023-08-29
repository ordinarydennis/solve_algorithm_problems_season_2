class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {

		if (board.empty() || board[0].empty())
		{
			return 0;
		}

		int r_size = static_cast<int>(board.size());
		int c_size = static_cast<int>(board[0].size());

		int ret = 0;

		for (int r = 0; r < r_size; r++)
		{
			for (int c = 0; c < c_size; c++)
			{
				if ('X' != board[r][c])
				{
					continue;
				}

				if (r != 0 && 'X' == board[r - 1][c])
				{
					continue;
				}
				
				if (c != 0 && 'X' == board[r][c - 1])
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
class Solution {

	void dfsLeft(vector<vector<char>>& board, vector<vector<bool>>& checked, int x, int y, int& count)
	{
		if (board[0].size() <= x)
		{
			return;
		}

		if ('.' == board[y][x])
		{
			return;
		}

		count++;

		checked[y][x] = true;

		dfsLeft(board, checked, x + 1, y, count);
	}

	void dfsDown(vector<vector<char>>& board, vector<vector<bool>>& checked, int x, int y, int& count)
	{
		if (board.size() <= y)
		{
			return;
		}
		
		if ('.' == board[y][x])
		{
			return;
		}

		count++;

		checked[y][x] = true;

		dfsDown(board, checked, x, y + 1, count);
	}

public:
	int countBattleships(vector<vector<char>>& board) {

		vector<vector<bool>> checked(board.size(), vector<bool>(board[0].size(), false));

		int ret = 0;

		for(int y = 0; y < board.size(); y++)
		{
			for (int x = 0; x < board.size(); x++)
			{
				if ('.' == board[y][x])
				{
					continue;
				}

				if (checked[y][x])
				{
					continue;
				}

				int count = 0;

				dfsLeft(board, checked, x, y, count);

				if (count)
				{
					ret++;
					continue;
				}

				dfsDown(board, checked, x, y, count);

				if (count)
				{
					ret++;
					continue;
				}
			}
		}

		return ret;
	}
};
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		vector<vector<char>> board2(board.size(), vector<char>(board[0].size(), '.'));

		std::set<char> cul;

		for (int y = 0; y < board.size(); y++)
		{
			std::set<char> row;

			for (int x = 0; x < board[0].size(); x++)
			{
				if ('.' != board[y][x])
				{
					if (0 == row.count(board[y][x])
					{
						row.insert(board[y][x]);
					}
					else
					{
						return false;
					}
				}
			}
		}

	}
};
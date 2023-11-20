class Solution
{
public:
	bool isValidSudoku(vector<vector<char> >& board)
	{
		int row[9][9] = {};
		int column[9][9] = {};
		int subBoard[9][9] = {};

		for (int r = 0; r < board.size(); r++)
		{
			for (int c = 0; c < board[0].size(); c++)
			{
				if ('.' == board[r][c])
				{
					continue;
				}

				int value = board[r][c] - '0' - 1;

				int k = (r / 3) * 3 + c / 3;


				if (row[r][value] || column[c][value] || subBoard[k][value])
				{
					return false;
				}

				row[r][value] = column[c][value] = subBoard[k][value] = 1;

			}
		}

		return true;
	}
};

//Three flags are used to check whether a number appear.
//used1: check each row
//used2 : check each column
//used3 : check each sub - boxes
//leetcode.com/problems/valid-sudoku/solutions/15464/my-short-solution-by-c-o-n2/?orderBy=most_votes


class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {

		int rMat[9][9] = {};
		int cMat[9][9] = {};
		int mMat[9][9] = {};

		for (int a = 0; a < 9; a++)
		{
			for (int b = 0; b < 9; b++)
			{
				if ('.' == board[a][b]) 
					continue;

				int val = board[a][b] - '0' - 1;

				int i = ((a / 3) * 3) + (b / 3);

				if (rMat[a][val] || cMat[b][val] || mMat[i][val])
					return false;

				rMat[a][val] = cMat[b][val] = mMat[i][val] = 1;
			}
		}

		return true;
	}
};
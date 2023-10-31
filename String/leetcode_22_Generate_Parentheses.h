class Solution {


	void dfs(string& s, int openCount, int closeCount, int n, vector<string>& ret)
	{
		if (s.size() == n * 2)
		{
			ret.push_back(s);
			return;
		}

		for (int i = 0; i < 2; i++)
		{
			if (n <= openCount && 0 == i)
				continue;
			}
			if (openCount <= closeCount && 1 == i)
				continue;

			s += (0 == i) ? '(' : ')';

			dfs(s, 
				i == 0 ? openCount + 1 : openCount, 
				i == 1 ? closeCount + 1 : closeCount, 
				n , ret
			);

			s.pop_back();
		}

	}

public:
	vector<string> generateParenthesis(int n) {

		vector<string> ret;

		string s = "(";

		dfs(s, 1, 0, n, ret);

		return ret;

	}
};
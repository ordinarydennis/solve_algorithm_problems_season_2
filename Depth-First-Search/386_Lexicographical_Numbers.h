class Solution {

	void dfs(int cur, int max, vector<int>& list)
	{
		if (max < cur)
			return;

		list.push_back(cur);

		for (int i = 0; i < 10; i++)
		{
			if (max <cur * 10 + i)
				return;

			dfs(cur * 10 + i, max, list);
		}
	}


public:
	vector<int> lexicalOrder(int n) {

		vector<int> ret;

		for (int i = 1; i < 10; i++)
		{
			dfs(i, n, ret);
		}
	
		return ret;
	}
};
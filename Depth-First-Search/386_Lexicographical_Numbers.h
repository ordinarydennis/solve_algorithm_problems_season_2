class Solution {

	void dfs(int num, int max, vector<int>& result)
	{
		if (max < num)
			return;

		result.push_back(num);

		for (int i = 0; i < 10; i++)
		{
			dfs((num * 10) + i, max, result);
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

//https://leetcode.com/problems/lexicographical-numbers/solutions/3638974/simple-easy-o-n-c-solution-using-recursion-dfs/
class Solution {
public:
	bool seen[16] = {};
	int res = 0;
	int dfs(int n, int pos = 1)
	{
		if (pos > n) 
			return res++;

		for (int i = 1; i <= n; i++)
		{
			if (!seen[i] && (i % pos == 0 || pos % i == 0))
			{
				// marking i as seen
				seen[i] = true;

				dfs(n, pos + 1);

				// backtracking
				seen[i] = false;
			}
		}
		return res;
	}

	int countArrangement(int n)
	{
		if (n < 4) 
			return n;

		return dfs(n);
	}
};

//i			1,2,3
//p[i]		1,2,3
//p[i]		1,3,2
//p[i]		2,1,3
//p[i]		2,3,1
//p[i]		3,1,2
//p[i]		3,2,1

//refer to https://leetcode.com/problems/beautiful-arrangement/solutions/1000788/c-backtracking-dfs-bitwise-solutions-compared-and-explained-100-time-95-space/?orderBy=most_votes

class Solution {

	void dfs(int start, int end, int& sum)
	{
		if (end <= start)
		{
			return;
		}

		if (end - start == 2)
		{
			return;
		}

		int mid = (end + start) / 2 + 1;
		int t = end - mid;

		if(t % 2 == 0)
		{
			mid++;
		}

		sum += mid;

		dfs(mid + 1, end, sum);

	}


public:
	int getMoneyAmount(int n) {

		int sum = 0;

		dfs(1, n, sum);

		return sum;
	}
};
class Solution {
	
	int dfs(int sum, vector<int>& prices, int index, int fee, bool isSell)
	{
		if (index <= prices.size())
		{
			return sum;
		}

		int max = 0;

		for(int i = index; i < prices.size(); i++)
		{
			if (isSell)
			{
				if (sum + prices[i] < fee)
				{
					continue;
				}
			}

			int s = (true == isSell) ? 1 : -1;

			int sum2 = sum + (s * prices[i]);

			if (isSell)
			{
				sum2 -= fee;
			}

			int ret = dfs(sum2, prices, i + 1, fee, !isSell);

			max = std::max(max, ret);
		}

		return max;
	}

public:
	int maxProfit(vector<int>& prices, int fee) {

		return dfs(0, prices, 0, fee, false);

	}
};
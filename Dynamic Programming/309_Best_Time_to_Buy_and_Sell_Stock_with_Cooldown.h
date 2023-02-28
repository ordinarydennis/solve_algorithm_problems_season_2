class Solution {
public:
	int maxProfit(vector<int>& p, int fee) {
		int n = p.size();

		if (n < 2) 
			return 0;

		vector<int> buy(n, 0), sell(n, 0);
		
		buy[0] = -p[0];
		
		for (int i = 1; i < n; i++)
		{
			buy[i] = max(buy[i - 1], sell[i - 1] - p[i]); // keep the same as day i-1, or buy from sell status at day i-1
			sell[i] = max(sell[i - 1], buy[i - 1] - fee + p[i]); // //keep the same as day i-1, or sell from buy status at day i-1
		}

		return sell[n - 1];
	}
};

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108884/java-c-clean-code-dp-greedy/?orderBy=most_votes
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108871/2-solutions-2-states-dp-solutions-clear-explanation/?orderBy=most_votes
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems/?orderBy=most_votes

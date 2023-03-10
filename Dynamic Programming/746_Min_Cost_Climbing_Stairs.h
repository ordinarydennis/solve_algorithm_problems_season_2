class Solution {

	std::unordered_map<int, int> memo;

	int dfs(vector<int>& cost, int index)
	{
		if (memo.count(index))
		{
			return memo[index];
		}

		if (cost.size() <= index)
		{
			return 0;
		}

		int ret = INT_MAX;

		for (int i = index + 1; i <= index + 2; i++)
		{
			int r = dfs(cost, i);

			ret = std::min(ret, cost[index] + r);
		}

		memo[index] = ret;

		return memo[index];
	}

public:
	int minCostClimbingStairs(vector<int>& cost) {

		if (1 == cost.size())
		{
			return cost[0];
		}

		return std::min(dfs(cost, 0), dfs(cost, 1));;
	}
};



You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, 
you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.



Example 1:

Input: cost = [10, 15, 20] 25
Output : 15
Explanation : You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2 :

	Input : cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
	Output : 6
	Explanation : You will start at index 0.
	- Pay 1 and climb two steps to reach index 2.
	- Pay 1 and climb two steps to reach index 4.
	- Pay 1 and climb two steps to reach index 6.
	- Pay 1 and climb one step to reach index 7.
	- Pay 1 and climb two steps to reach index 9.
	- Pay 1 and climb one step to reach the top.
	The total cost is 6.
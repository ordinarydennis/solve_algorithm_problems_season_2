class Solution {
public:

    // Recursive Soltion
    // Time : O(2^N)
    // Space : O(N)

    int solveRec(vector<int>& prices, int day, bool buy) {

        if (day >= prices.size()) {
            return 0;
        }

        // First Choice
        int ans1 = solveRec(prices, day + 1, buy); // no transaction this day


        // Second Choice
        int ans2 = 0;
        // doing the required transaction this day
        if (buy) {
            ans2 = -prices[day] + solveRec(prices, day + 1, false);
        }
        else {
            ans2 = prices[day] + solveRec(prices, day + 2, true);
        }

        return max(ans1, ans2);

    }

    int maxProfit(vector<int>& prices) {

        int ans = 0;

        // Recursive Solution 
        ans = solveRec(prices, 0, true);

        // Memoization Solution
        // vector<vector<int>> memo(prices.size() + 2, vector<int>(2, -1));
        // ans = solveMemo(prices, 0, true, memo);

         // DP solution with O(N) space
        // ans = solveDP1(prices);

        // DP solution with O(1) space
        //ans = solveDP2(prices);


        return ans;

    }



};

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/1521820/c-four-solutions-recursion-memoization-dp-with-o-n-space-dp-with-o-1-space/?orderBy=most_votes

class Solution {
public:
    bool divisorGame(int N) {

        vector<bool> dp(N + 1, false);
        
        dp[2] = true;
        
        for (int i = 3; i <= N; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (i % j == 0 && dp[i - j] == false) 
                    dp[i] = true;
            }
        }
        return dp[N];
    }
};
//dp[i - j] == false means that it is result of the game in next turn.
//because i - j is value that player take.
//dp[i - j] == false means that opponents will lose the game in next turn. 


//https://leetcode.com/problems/divisor-game/solutions/274608/simple-dp-java-solution/?orderBy=most_votes
//https://leetcode.com/problems/divisor-game/solutions/1083463/c-dp-solution-with-explanation/?orderBy=most_votes&page=2
//https://bitwise.tistory.com/475

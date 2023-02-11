class Solution {

    bool dp(int n, bool isAlice)
    {
        if (n <= 1)
        {
            return !isAlice;
        }

        for (int i = n - 1; 1 <= i; i--)
        {
            if (n % i == 0)
            {
                n -= i;

                if (false == dp(n, !isAlice))
                {
                    return false;
                }
            }
        }

        return true;
    }


public:
    bool divisorGame(int n) {

        return  dp(n, true);

    }
};
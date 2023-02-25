class Solution {
public:
    int getMaximumGenerated(int n) {

        if (0 == n || 1 == n)
        {
            return n;
        }

        std::vector<int> v(n + 1, 0);

        v[0] = 0;
        v[1] = 1;

        int index = 0;

        int ret = 0;

        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                index++;
                v[i] = v[index];
            }
            else
            {
                v[i] = v[index] + v[index + 1];    
            }

            ret = std::max(ret, v[i]);
        }

        return ret;
    }
};
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int count = 0;

        int ret = INT_MIN;

        for (int i = 1; i < nums.size(); i++)
        {
            if (0 < nums[i] - nums[i - 1])
            {
                count++;
            }
            else
            {
                ret = std::max(ret, count);
                count = 0;
            }
        }

        if (ret == INT_MIN)
        {
            ret = count;
        }

        return ret + 1;
    }
};
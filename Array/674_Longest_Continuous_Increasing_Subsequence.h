class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int count = 0;

        int ret = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                count++;
            }
            else
            {
                ret = std::max(ret, count);
                count = 0;
            }
        }

        ret = std::max(ret, count);

        return ret + 1;
    }
};
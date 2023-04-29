class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int ret = 0;

        int count = 0;

        for (int i = 0; i <= nums.size(); i++)
        {
            if (i < nums.size() && nums[i])
            {
                count++;
            }
            else
            {
                ret = std::max(ret, count);
                count = 0;
            }
        }

        return ret;
    }
};
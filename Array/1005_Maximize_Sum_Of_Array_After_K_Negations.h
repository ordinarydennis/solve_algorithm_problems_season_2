class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        std::sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++)
        {
            if (0 == k)
            {
                break;
            }

            if (nums[i] < 0)
            {
                nums[i] *= (-1);
                k--;
            }
            else if (0 == nums[i])
            {
                break;
            }
            else if(0 < nums[i])
            {
                if (k % 2 != 0)
                {
                    nums[i] *= (-1);
                }
                break;
            }
        }

        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};
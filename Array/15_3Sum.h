class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ret;

        for (int a = 0; a < nums.size() - 2; a++)
        {
            for (int b = a + 1; b < nums.size() - 1; b++)
            {
                for (int c = b + 1; c < nums.size(); c++)
                {
                    if (0 == nums[a] + nums[b] + nums[c])
                    {
                        vector<int> v = { nums[a] , nums[b] , nums[c] };
                        std::sort(v.begin(), v.end());

                        if (std::find(ret.begin(), ret.end(), v) == ret.end())
                        {
                            ret.push_back(std::move(v));
                        }
                    }
                }
            }
        }

        return ret;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ret = INT_MIN;

        for (int l = 1; l <= nums.size(); l++)
        {
            for (int i = 0; i <= nums.size() - l; i++)
            {
                int sum = std::accumulate(nums.begin() + i, nums.begin() + i + l, 0);

                ret = std::max(ret, sum);
            }
        }

        return ret;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ret = INT_MIN;

        vector<vector<int>> mat(nums.size(), vector<int>(nums.size()));

        for (int i = 0; i < nums.size(); i++)
        {
            mat[i][0] = nums[i];
            ret = std::max(ret, mat[i][0]);
        }

        for (int l = 1; l <= nums.size(); l++)
        {
            for (int i = 0; i < nums.size() - l; i++)
            {
                mat[i][l] = mat[i][l - 1] + nums[i + l];
                ret = std::max(ret, mat[i][l]);
            }
        }

        return ret;
    }
};
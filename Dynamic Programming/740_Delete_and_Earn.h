class Solution {

    int max = 0;

    void dfs(std::unordered_set<int>& visit, vector<int>& nums, int index, std::unordered_set<int>& us, int sum)
    {
        if (nums.size() <= index)
        {
            max = std::max(max, sum);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visit.count(i))
            {
                continue;
            }

            int sum2 = sum;

            if (0 == us.count(nums[i]))
            {
                sum2 += nums[i];
            }

            visit.insert(i);

            us.insert(nums[i] + 1);
            us.insert(nums[i] - 1);
            
            dfs(visit, nums, index + 1, us, sum2);

            us.erase(nums[i] + 1);
            us.erase(nums[i] - 1);

            visit.erase(i);
        }
    }

public:
    int deleteAndEarn(vector<int>& nums) {

        std::unordered_set<int> visit;
        std::unordered_set<int> us;

        dfs(visit, nums, 0, us, 0);

        return max;
    }
};
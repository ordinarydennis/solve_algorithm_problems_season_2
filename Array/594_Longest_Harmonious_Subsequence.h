class Solution {
public:
    int findLHS(vector<int>& nums) {

        std::map<int, int> m;

        for (int i = 0;i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        auto it = m.begin();

        int pre = it->first;
        int val = it->second;

        ++it;

        int ret = 0;

        while(m.end() != it)
        {
            if (it->first - pre == 1)
            {
                ret = std::max(ret, it->second + val);
            }

            pre = it->first;
            val = it->second;
            ++it;
        }

        return ret;
    }
};
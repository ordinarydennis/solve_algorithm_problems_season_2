class Solution {
public:
    int thirdMax(vector<int>& nums) {

        std::set<int, greater<int>> set;

        for (int i = 0; i < nums.size(); i++)
        {
            set.insert(nums[i]);
        }

        auto it = set.begin();

        if (set.size() < 3)
        {
            return *it;
        }
        
        std::advance(it, 2);

        return *it;
    }
};
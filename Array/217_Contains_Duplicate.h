class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        std::unordered_set<int> s;

        for (int n : nums)
        {
            auto it = s.insert(n);

            if (false == it.second)
            {
                return true;
            }

        }

        return false;

    }
};
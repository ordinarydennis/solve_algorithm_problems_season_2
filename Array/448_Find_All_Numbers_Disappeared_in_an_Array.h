class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        std::set<int> set;

        for (auto n : nums)
        {
            set.insert(n);
        }

        std::vector<int> ret;

		for (int i = 1; i <= nums.size(); i++)
        {
            if (0 == set.count(i))
            {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
class Solution {

    std::set<int> ss;

    void search(std::vector<int>& nums, int start, int end, int target)
    {
        if (end < start)
        {
            return;
        }

        int middle = (start + end) / 2;

        if (target == nums[middle])
        {
            ss.insert(middle);
        }

        if (nums[middle] < target)
        {
            search(nums, middle + 1, end, target);
        }
        else
        {
            search(nums, start, middle, target);
        }

    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {

        search(nums, 0, nums.size(), target);

        std::vector<int> ret;

       // std::vector<int> ret = { (*ss.begin()), *(ss.rbegin()) };

        return ret;
    }
};
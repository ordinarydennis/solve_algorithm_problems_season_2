class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        int ei = 0;
        int oi = 1;

        std::vector<int> ret(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                ret[ei] = nums[i];
                ei += 2;
            }
            else
            {
                ret[oi] = nums[i];
                oi += 2;
            }
        }

        return ret;

    }
};


//https://leetcode.com/problems/sort-array-by-parity-ii/solutions/1490847/c-two-pointers-solution/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        int ei = 0;
        int oi = 1;

        while (ei < nums.size() && oi < nums.size())
        {
            if (nums[ei] % 2 == 1 && nums[oi] % 2 == 0)
            {
                std::swap(nums[ei], nums[oi]);
            }
            else if(nums[ei] % 2 == 0)
            {
                ei += 2;
            }
            else if (nums[oi] % 2 == 1)
            {
                oi += 2;
            }


        }

        return nums;
    }
};
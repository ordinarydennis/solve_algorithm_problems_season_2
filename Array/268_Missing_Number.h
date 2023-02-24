class Solution {
public:
    int missingNumber(vector<int>& nums) {

        for (int i = 0; i <= nums.size(); i++)
        {
            auto it = find(nums.begin(), nums.end(), i);

            if (nums.end() == it)
            {
                return i;
            }
        
        }

        return 0;
    }
};
class Solution {
public:
    int arrayNesting(vector<int>& nums) {

        int ret = 0;

        std::unordered_set<int> memo;

        for (int i = 0; i < nums.size(); i++)
        {
            if (memo.count(i))
            {
                continue;
            }

            int first = nums[i];

            int nIndex = i;

            int count = 0;
            
            do           
            {
                memo.insert(nIndex);

                nIndex = nums[nIndex];
             
                count++;

            } while (first != nums[nIndex]);

            ret = std::max(ret, count);
        }

        return ret;
    }
};
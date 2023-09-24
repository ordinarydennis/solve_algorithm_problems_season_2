class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ret;

        int isInterIndex = 0;

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int a = isInterIndex; a < nums2.size(); a++)
            {
                if (nums1[i] != nums2[a])
                {
                    if (isInterIndex)
                    {
                        return ret;
                    }
                    continue;
                }

                if (0 == isInterIndex)
                {
                    ret.push_back(nums1[i]);
                    isInterIndex = a + 1;
                    break;
                }

                ret.push_back(nums1[i]);
                isInterIndex = a + 1;

            }
        }

        return ret;
    }
};
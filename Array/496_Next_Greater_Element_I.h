class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ret;

        for (int i = 0; i < nums1.size(); i++)
        {
            auto it = std::find(nums2.begin(), nums2.end(), nums1[i]);

            if (nums2.end() == it)
            {
                ret.push_back(-1);
            }
            else
            {
                bool isFind = false;

                while(++it < nums2.end())
                {
                    if (nums1[i] < *it)
                    {
                        ret.push_back(*it);
                        isFind = true;
                        break;
                    }
                }

                if (false == isFind)
                {
                    ret.push_back(-1);
                }
            }
        }

        return ret;
    }
};

//need to read solution
//https://leetcode.com/problems/next-greater-element-i/solutions/671261/c-map-stack-commented/?orderBy=most_votes&languageTags=cpp

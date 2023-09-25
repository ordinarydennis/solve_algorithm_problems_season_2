class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        std::unordered_set<int> set(nums1.begin(), nums1.end());

        vector<int> ret;

        for (int n : nums2)
        {
            if (set.count(n))
            {
                ret.push_back(n);
                set.erase(n);
            }
        }




        return ret;
    }
};
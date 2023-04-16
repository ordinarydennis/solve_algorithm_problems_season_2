class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        std::unordered_map<int,int> nM1;
        std::unordered_map<int,int> nM2;

        for (int i = 0; i < nums1.size(); i++)
        {
            nM1[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            nM2[nums2[i]]++;
        }

        std::vector<int> ret;

        for (const auto [n, c] : nM1)
        {
            auto it = nM2.find(n);

            if (nM2.end() == it)
            {
                continue;
            }

            int mc = std::min(c, it->second);

			for (int i = 0; i < mc; i++)
            {
                ret.push_back(n);
            }

        }

        return ret;
    }
};
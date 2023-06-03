class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

		int a = 0;
		int b = 0;
		std::vector<std::pair<int, int>> pList;
 
		std::unordered_map<int, int> m;

		while (a < nums1.size() || b < nums2.size())
		{
			if (a < nums1.size() && b < nums2.size())
			{
				if (nums1[a] < nums2[b])
				{
					pList.push_back({ 0, nums1[a++] });
				}
				else
				{
					pList.push_back({ 1, nums2[b++] });
				}
				continue;
			}

			while(a < nums1.size())
			{
				pList.push_back({ 0, nums1[a++] });
			}

			while (b < nums2.size())
			{
				pList.push_back({ 1, nums2[b++] });
			}
		}

		std::set<int> check;

		vector<vector<int>> ret;

		for(int i = 0; i < pList.size(); i++)
		{
			auto p1 = pList[i];

			for (int j = 0; j < pList.size(); j++)
			{
				if (i == j)
				{
					continue;
				}

				if (check.count(j))
				{
					continue;
				}

				auto p2 = pList[j];

				if (p1.first == p2.first)
				{
					continue;
				}

				ret.push_back(vector<int>{ p1.second, p2.second});

				check.insert(i);

				if (k <= ret.size())
				{
					return ret;
				}

				break;
			}
		}

		return ret;

	}
};
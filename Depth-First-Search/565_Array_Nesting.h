class Solution {
public:
	int arrayNesting(vector<int>& nums) {

		int ret = 0;

		std::unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); i++)
		{
			std::unordered_set<int> s;
			
			int n = nums[i];
			
			int k = -1;

			while (0 == s.count(n))
			{
				s.insert(n);

				n = nums[n];				

				auto it = m.find(n);

				if (it != m.end())
				{
					k = it->second;
					break;
				}
				
			}
			
			if (-1 < k)
			{
				ret = std::max(k, ret);
			}
			else
			{
				ret = std::max(static_cast<int>(s.size()), ret);
			}

			m.emplace(i, ret);
		}

		return ret;
	}
};
class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {

		std::unordered_map<int, int> m;

		int max = INT_MIN;

		for (int n : nums)
		{
			m[n]++;
			max = std::max(m[n], max);
		}

		int ret = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			int min = INT_MAX;

			m.clear();

			for (int j = i; j < nums.size(); j++)
			{
				m[j]++;

				if (max == m[j])
				{
					if (max == j - i + 1)
					{
						return max;
					}
					else
					{
						min = std::min(min, j - i + 1);
						ret = min;
						break;
					}
				}
			}
		}

		return ret;

	}
};
class Solution {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {

		std::multimap<int, int> m;

		for (int i = 0; i  < nums.size(); i++)
		{
			m.emplace(nums[i], i);
		}


		for (const auto& [n, index] : m)
		{
			if (n < 0)
			{
				k--;
				nums[index] = -nums[index];
			}
			else if (0 == n)
			{
				break;
			}
			else
			{
				k = k % 2;
				//positive..
				if (1 <= k)
				{
					k--;
					nums[index] = -nums[index];
				}
			}

			if (k <= 0)
			{
				break;
			}
		}

		for (auto [n, inde] : m)
		{
			cout << n << " ";
		}
		cout << endl;
		for (auto n : nums)
		{
			cout << n << " ";
		}

		return std::accumulate(nums.begin(), nums.end(), 0);

	}
};

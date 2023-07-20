class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& arr) {

		std::sort(arr.begin(), arr.end());

		int sum = std::accumulate(arr.begin(), arr.end(), 0);

		std::unordered_set<int> checker;

		int count = 0;

		int target = sum / 3;

		for (int c = 0; c < 3; c++)
		{
			int s = 0;

			for (int i = 0; i < arr.size(); i++)
			{
				if (checker.count(i))
				{
					continue;
				}
				
				if (s + arr[i] <= target)
				{
					s += arr[i];
					checker.insert(i);
					if (s == target)
					{
						break;
					}
				}
				else
				{
					break;
				}
			}

			if (s == target)
			{
				count++;
			}
		}

		return 3 == count;
	}
};
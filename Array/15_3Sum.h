class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& num) {


		std::sort(num.begin(), num.end());

		std::vector<std::vector<int>> ret;
		int max = static_cast<int>(num.size());

		for (int i = 0; i < max; i++)
		{
			int l = i + 1;
			int r = max - 1;
			int t = -1 * num[i];

			while (l < r)
			{
				int sum = num[l] + num[r];

				if (t < sum)
				{
					r--;
				}
				else if (sum < t)
				{
					l++;
				}
				else
				{
					std::vector<int> triplet = { num[i], num[l], num[r] };

					while (l < r && triplet[1] == num[l]) l++;

					while (l < r && triplet[2] == num[r]) r--;

					ret.emplace_back(std::move(triplet));
				}


				while (i + 1 < max && num[i] == num[i + 1]) i++;
			}
		}

		return ret;

	}
};

//https://leetcode.com/problems/3sum/solutions/7402/share-my-ac-c-solution-around-50ms-o-n-n-with-explanation-and-comments/

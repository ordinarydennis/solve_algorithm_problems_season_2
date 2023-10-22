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


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		std::sort(nums.begin(), nums.end());

		vector<vector<int>> ret;

		int max = static_cast<int>(nums.size() - 1);

		for (int i = 0; i < nums.size(); i++)
		{
			int t = -1 * nums[i];
			int l = i + 1;
			int r = max;

			while (l < r)
			{
				if (t < nums[l] + nums[r])
				{
					r--;
				}
				else if (t > nums[l] + nums[r])
				{
					l++;
				}
				else
				{
					std::vector<int> find = { nums[i], nums[l], nums[r] };

					ret.push_back(find);

					while (l < r && find[1] == nums[l]) l++;
					while (l < r && find[2] == nums[r]) r--;
				}

				while (i < max && nums[i] == nums[i + 1]) i++;
			}
		}

		return ret;

	}
};


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		int max = static_cast<int>(nums.size());

		std::sort(nums.begin(), nums.end());

		vector<vector<int>> ret;

		for (int i = 0; i < max; i++)
		{
			int target = -1 * nums[i];

			int l = i + 1;
			int r = max - 1;

			while (l < r)
			{
				if (target < nums[l] + nums[r])
				{
					r--;
				}
				else if (target > nums[l] + nums[r])
				{
					l++;
				}
				else
				{
					std::vector<int> f = { nums[i], nums[l], nums[r] };

					while (l < r && f[1] == nums[l]) l++;
					while (l < r && f[2] == nums[r]) r--;

					ret.emplace_back(std::move(f));
				}
			}

			while (i + 1 < max && nums[i] == nums[i + 1]) i++;
		}

		return ret;
	}
};
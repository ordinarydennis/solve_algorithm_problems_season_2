class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {

		if (nums.size() == 0)
		{
			return {};
		}

		vector<string> ret;

		int cur = nums[0];
		int end = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			int n2 = nums[i];
			int n1 = nums[i - 1];

			if (nums[i] < 0)
			{
				n2 += 1;
				n1 += 1;

				n2 *= -1;
				n1 *= -1;
			}

			if (1 == n2 - n1)
			{
				end = nums[i];
				continue;
			}
			else
			{
				if (cur != end)
				{
					string s = to_string(cur) + "->" + to_string(end);
					ret.push_back(std::move(s));

				}
				else
				{
					string s = to_string(cur);
					ret.push_back(std::move(s));
				}
				cur = nums[i];
				end = nums[i];
			}
		}

		if (cur == nums[nums.size() - 1])
		{
			string s = to_string(cur);
			ret.push_back(std::move(s));
		}
		else
		{
			string s = to_string(cur) + "->" + to_string(end);
			ret.push_back(std::move(s));
		}

		return ret;

	}
};

Input: nums = [0, 1, 2, 4, 5, 7]
Output : ["0->2", "4->5", "7"]
Explanation : The ranges are :
[0, 2] -- > "0->2"
[4, 5] -- > "4->5"
[7, 7] -- > "7"

[0, 2, 3, 4, 6, 8, 9]

[0, 2, 3, 4, 6, 8, 9]
Output
["0", "2->4", "6->4", "8->9"]
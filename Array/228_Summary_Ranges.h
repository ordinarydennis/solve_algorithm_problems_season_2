class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {

		if (nums.empty())
		{
			return {};
		}

		vector<string> ret;

		int s = nums[0];
		
		for (int i = 0; i < nums.size(); i++)
		{
			if (i == nums.size() - 1 || nums[i] + 1 != nums[i + 1])
			{
				string str;
				
				if (s != nums[i])
				{
					str = to_string(s) + "->" + to_string(nums[i]);
				}
				else
				{
					str = to_string(s);
				}
				
				ret.push_back(std::move(str));

				if (i == nums.size() - 1)
				{
					break;
				}

				s = nums[i + 1];
				
			}
		}

		return ret;
	}
};

//https://leetcode.com/problems/summary-ranges/solutions/1805321/c-0ms-100-easy-to-understand-full-explanation/?orderBy=most_votes
class Solution {
public:
	string largestNumber(vector<int>& nums) {


		std::sort(nums.begin(), nums.end(), [](int l, int r) {
				
			string lstr = to_string(l);
			string rstr = to_string(r);

			std::string s1 = lstr + rstr;
			std::string s2 = rstr + lstr;

			return 0 < s1.compare(s2);

			}
		);

		if (0 == nums[0])
		{
			return "0";
		}
		
		std::string ret;

		for (int n : nums)
		{
			ret += to_string(n);
		}

		return ret;
	}
};

//https://leetcode.com/problems/largest-number/solutions/53158/my-java-solution-to-share/

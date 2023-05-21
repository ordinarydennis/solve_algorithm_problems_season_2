class Solution {
public:
	string largestNumber(vector<int>& nums) {


		std::sort(nums.begin(), nums.end(), [](int l, int r) {
				
			string lstr = to_string(l);
			string rstr = to_string(r);

			int i = 0;
			int j = 0;

			int ret = 0;

			while (i < lstr.size() && j < rstr.size())
			{
				if (lstr[i] == rstr[j])
				{
					i++;
					j++;
					continue;
				}

				if (rstr[j] < lstr[i])
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			if (lstr.size() < rstr.size())
			{
				if ('0' == rstr[j])
				{
					return true;
				}
				else
					return false;
			}
			else
			{
				if ('0' == lstr[i])
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			
			return lstr.size() < rstr.size();
			
			}
		);

		std::string ret;

		for (int n : nums)
		{
			ret += to_string(n);
		}

		return ret;
	}
};
class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {

		vector<int> ret;

		std::unordered_set<int> s;

		for (int n : nums)
		{
			if (s.count(n))
			{
				ret.push_back(n);
				continue;
			}

			s.insert(n);
		}

		for (int i = 1; i <= nums.size(); i++)
		{
			if (0 == s.count(i))
			{
				ret.push_back(i);
				break;
			}
		}

		return ret;
	}
};

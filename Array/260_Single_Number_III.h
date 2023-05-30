class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {

		std::unordered_set<int> s;

		for (int i = 0; i < nums.size(); i++)
		{
			if (s.count(nums[i]))
			{
				s.erase(nums[i]);
			}
			else
			{
				s.insert(nums[i]);
			}
		}

		vector<int> ret;

		for (int e : s)
		{
			ret.push_back(e);
		}

		return ret;

	}
};
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {

		std::multiset<int>  s;

		for (int i = 0; i < nums.size(); i++)
		{
			s.insert(nums[i] * nums[i]);
		}

		//std::vector<int> ret(s.begin(), s.end());

		std::vector<int> ret(s.size());
		std::copy(s.begin(), s.end(), ret.begin());

		return ret;

	}
};
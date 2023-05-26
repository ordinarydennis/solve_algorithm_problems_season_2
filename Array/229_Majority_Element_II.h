class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {

		int needCount = nums.size() / 3 + 1;

		std::unordered_map<int, std::pair<int,bool>> m;

		std::vector<int> ret;

		for (int n : nums)
		{
			auto& p = m[n];

			p.first++;

			if (needCount <= p.first && false == p.second)
			{
				p.second = true;
				ret.push_back(n);
			}
		}

		return ret;
	}
};
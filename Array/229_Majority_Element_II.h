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

class Solution {
public:
	vector<int> majorityElement(vector<int>& a)
	{
		int y(-1), z(-1), cy(0), cz(0);

		for (const auto& x : a)
		{
			if (x == y) cy++;
			else if (x == z) cz++;
			else if (!cy) y = x, cy = 1;
			else if (!cz) z = x, cz = 1;
			else cy--, cz--;
		}

		cy = cz = 0;
		for (const auto& x : a)
			if (x == y) cy++;
			else if (x == z) cz++;

		vector<int> r;
		if (cy > size(a) / 3) r.push_back(y);
		if (cz > size(a) / 3) r.push_back(z);
		return r;
	}
};
//https://leetcode.com/problems/majority-element-ii/solutions/543672/boyer-moore-majority-vote-algorithm-explained/
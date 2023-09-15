class Solution {
public:
	int arrayNesting(vector<int>& nums) {

		int ret = 0;

		std::unordered_set<int> s;

		for (int i = 0; i < nums.size(); i++)
		{
			if (s.count(i))
				continue;

			int n = nums[i];
			
			int start = i;

			int count = 0;

			do
			{
				count++;

				s.insert(start);

				start = nums[start];

			} while (n != nums[start]);

			ret = std::max(ret, count);
		}

		return ret;
	}
};

//https://leetcode.com/problems/array-nesting/editorial/
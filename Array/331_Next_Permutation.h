class Solution {

	std::unordered_set<int> memo;

	void dfs(vector<int>& nums, vector<int>& list, vector<vector<int>>& ret)
	{
		if (list.size() == nums.size())
		{
			ret.push_back(list);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (memo.count(i))
			{
				continue;
			}
			
			memo.insert(i);
	
			list.push_back(nums[i]);

			dfs(nums, list, ret);

			list.pop_back();

			memo.erase(i);

		}
	}


public:
	void nextPermutation(vector<int>& nums) {

		vector<vector<int>> ret;

		vector<int> list;

		dfs(nums, list, ret);

		auto it = std::find_if(ret.begin(), ret.end(), [&nums](vector<int>& nlist) {

			return nums == nlist;

			}
		);

		++it;

		if (ret.end() == it)
		{
			nums = *ret.begin();
		}
		else
		{
			nums = *(it);
		}

	}
};
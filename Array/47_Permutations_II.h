class Solution {

	vector<vector<int>> ret;

	std::map<int, bool> visit;

	void makePermute(const vector<int>& nums, vector<int>& list)
	{
		if (nums.size() == list.size())
		{
			if (ret.end() == std::find(ret.begin(), ret.end(), list))
			{
				ret.push_back(list);
			}
			
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (visit[i])
			{
				continue;
			}

			visit[i] = true;

			list.push_back(nums[i]);

			makePermute(nums, list);

			list.pop_back();

			visit[i] = false;
		}
	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {

		vector<int> list;

		makePermute(nums, list);

		return ret;
	}
};
Input
intervals =
[[1, 3], [6, 9]]
newInterval =
[2, 5]

Output
[[0, 0, 1, 6]]
Expected
[[1, 5], [6, 9]]



class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {


		if (newInterval.empty())
			return {};

		int start = newInterval[0];
		int end = newInterval[1];

		vector<vector<int>> ret;

		vector<int> v(2);
		bool insert = false;
		for (int i = 0; i < intervals.size(); i++)
		{
			if (insert)
			{
				ret.push_back(intervals[i]);
				continue;
			}

			if (intervals[i][1] < start)
			{
				ret.push_back(intervals[i]);
			}
			else
			{
				if(intervals[i][0] < start && end < intervals[i][1])
				{
					ret.push_back(intervals[i]);
					insert = true;
				}
				else if (end < intervals[i][0])
				{
					v.push_back(intervals[i][0]);
					v.push_back(intervals[i][1]);
					ret.push_back(std::move(v));
					insert = true;
				}
				else
				{
					if (0 == v[0])
					{
						v.push_back(intervals[i][0]);
					}
					
					if (end < intervals[i][1])
					{
						v.push_back(intervals[i][1]);
						ret.push_back(std::move(v));
						insert = true;
					}
					else
					{
						v.push_back(end);
						ret.push_back(std::move(v));
						insert = true;
					}
				}
			}

		}

		return ret;

	}
};
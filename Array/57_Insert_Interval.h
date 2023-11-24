class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

		vector<vector<int>> ret;

		int i = 0;

		//determine the starting point
		while (i < intervals.size() && intervals[i][1] < newInterval[0]) ret.push_back(intervals[i++]);

		//starting point(newInterval[0]) is less than intervals[0]  or intervals[1] 
		
		//determine the end point
		//end point(newInterval[1]) is greater than intervals[0]  or intervals[1] 
		while (i < intervals.size() && intervals[i][0] <= newInterval[1])
		{
			newInterval[0] = std::min(newInterval[0], intervals[i][0]);
			newInterval[1] = std::max(newInterval[1], intervals[i++][1]);
		}

		ret.push_back(newInterval);

		while (i < intervals.size()) ret.push_back(intervals[i++]);

		return ret;
	}
};
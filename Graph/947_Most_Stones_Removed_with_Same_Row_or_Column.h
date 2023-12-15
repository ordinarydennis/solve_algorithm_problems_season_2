class Solution {
public:
	int removeStones(vector<vector<int>>& stones) {

		map<int, set<int>> mat;

		for (auto s : stones)
		{
			mat[s[0]].insert(s[1]);
			mat[s[1]].insert(s[0]);
		}

		int ret = 0;

		for (auto sit = stones.rbegin(); sit != stones.rend(); ++sit)
		{
			auto it = mat.find((*sit)[0]);
			auto it2 = mat.find((*sit)[1]);

			if(mat.end() != it)
			{
				if (it->second.count((*sit)[1]))
				{
					it->second.erase((*sit)[1]);
					mat[(*sit)[1]].erase((*sit)[0]);
					ret++;
				}
			}
			else if (mat.end() != it2)
			{
				it->second.erase((*sit)[1]);
				mat[(*it)[0]].erase((*sit)[1]);
				ret++;
			}
		}

		return ret;
	}
};
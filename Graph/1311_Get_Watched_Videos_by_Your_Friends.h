class Solution {

	std::set<string> s;

	void traversal(int level, int startId, int index, vector<vector<int>>& friends, vector<vector<string>>& watchedVideos)
	{
		if (0 == level)
		{
			for(auto str : watchedVideos[index])
			{
				s.insert(str);
			}

			return;
		}

		for(int n : friends[index])
		{ 
			if (startId == index)
				continue;
		
			traversal(level - 1, startId, n, friends, watchedVideos);
		}
	}


public:
	vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {

		traversal(level, id, id, friends, watchedVideos);

		vector<string> ret(s.begin(), s.end());

		return ret;
	}
};
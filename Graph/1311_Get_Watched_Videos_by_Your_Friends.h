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

// First of All Please Try This Question. This Is A bit Complex to Understand But Once you Will get it
// You will Implement it easily.
// See What the Question States that you are given some id You Need to Go to Its Next levels And How Levels Are Mentioned of friends that you can see in friends Array.
// So Go to id friends that' level = 1 then further go 
// to their frinds that would be level =2.
// And correspondingly do so. So Upto here I did BFS And Reached to its next to next levels Correspondingly.
// So After That When I reached level given in question I break out 
// of bfs at this situation my queue is stored with all the friends 
// which come in that level for given id.
// And then after here I just traversed the watchedVideos Array 
// stored the string frequency in map and t At last since i need to sort with
// Frequency And then I Also Need to sort accordingly so i made a 
// priority queue of pair and sort both frequency and val according to cmp class
// as i made it above.

struct cmp
{
	bool operator()(pair<int, string> const& a, pair<int, string> const& b) {
		if (a.first == b.first)
		{
			return a.second > b.second;
		}
		return a.first > b.first;
	}
};
class Solution {
public:
	typedef pair<int, string>pd;
	vector<string> watchedVideosByFriends(vector<vector<string>>& nums, vector<vector<int>>& friends, int id, int level) {
		int n = nums.size();
		vector<int>vis(n + 1, 0);
		queue<int>q;
		q.push(id);
		vis[id] = 1;
		int lvl = -1;
		while (!q.empty())
		{
			int sz = q.size();
			lvl++;
			if (lvl == level)
			{
				break;
			}
			while (sz--)
			{
				int val = q.front();
				q.pop();
				for (int i = 0; i < friends[val].size(); i++)
				{
					if (!vis[friends[val][i]])
					{
						q.push(friends[val][i]);
						vis[friends[val][i]] = 1;
					}
				}
			}
		}
		map<string, int>seen;
		while (!q.empty())
		{
			int val = q.front();
			for (int i = 0; i < nums[val].size(); i++)
			{
				seen[nums[val][i]]++;
			}
			q.pop();
		}
		priority_queue<pd, vector<pd>, cmp>pq;
		for (auto it : seen)
		{
			pq.push({ it.second,it.first });
		}
		vector<string>ans;
		while (!pq.empty())
		{
			ans.push_back(pq.top().second);
			pq.pop();
		}
		return ans;
	}
};

//https://leetcode.com/problems/get-watched-videos-by-your-friends/solutions/2126446/c-explained-briefly-each-and-every-point/

class Solution {
public:
	vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
		unordered_set<int> visited;
		deque<int> q;
		q.push_back(id);
		visited.insert(id);
		int l = 0, sz = 0;
		while (!q.empty() && l < level) {
			sz = q.size();
			for (int i = 0;i < sz;i++) {
				for (auto f : friends[q.front()]) {
					if (visited.find(f) == visited.end()) {
						visited.insert(f);
						q.push_back(f);
					}
				}
				q.pop_front();
			}
			l++;
		}
		unordered_map<string, int> v;
		for (auto item : q) {
			for (auto wv : watchedVideos[item]) v[wv]++;
		}
		vector<string> ans;
		for (auto [k, _] : v) ans.push_back(k);
		sort(ans.begin(), ans.end(), [&v](auto f, auto s) {return v[f] != v[s] ? v[f] < v[s] : (f < s);});

		return ans;
	}
};
//https://leetcode.com/problems/get-watched-videos-by-your-friends/solutions/4212062/c-bfs-map/
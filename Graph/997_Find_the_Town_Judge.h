class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {

		if (1 == n)
		{
			return 1;
		}

		unordered_map<int, int> rMap;
		unordered_map<int, int> cMap;
		vector<int> candidates;

		for (const auto& t : trust)
		{
			rMap[t[0]] = t[1];
			cMap[t[1]]++;
			if (n - 1 == cMap[t[1]])
			{
				candidates.push_back(t[1]);
			}
		}

		for (int c : candidates)
		{
			if (false == rMap.count(c))
			{
				return c;
			}
		}


		return -1;
	}
};


class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {

		if (1 == n)
			return 1;


		vector<int> degree(n + 1);

		for (const auto& t : trust)
		{
			degree[t[0]]--;
			degree[t[1]]++;
		}

		for (int i = 1; i <= n; i++)
		{
			if (n - 1 == degree[i]) return i;
		}

		return -1;
	}
};

//https://leetcode.com/problems/find-the-town-judge/solutions/3088104/day-23-easiest-beginner-friendly-solution-o-n-time-and-o-n-space/
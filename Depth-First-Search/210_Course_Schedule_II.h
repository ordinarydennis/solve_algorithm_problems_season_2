class Solution {

	std::unordered_set<int> memo;

	std::unordered_set<int> todo;

	bool find(const std::unordered_map<int, vector<int>>& graph, int preCourse, vector<int>& ret)
	{
		if (memo.count(preCourse))
			return true;

		if (todo.count(preCourse))
			return false;

		memo.insert(preCourse);
		todo.insert(preCourse);

		auto it = graph.find(preCourse);

		if (graph.end() != it)
		{
			for (int c : it->second)
			{
				if (false == find(graph, c, ret))
					return false;
			}
		}

		ret.push_back(preCourse);
		todo.erase(preCourse);
		return true;
	}

public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

		vector<int> ret;

		std::unordered_map<int, vector<int>> graph;

		for (const auto& p : prerequisites)
		{
			graph[p[1]].push_back(p[0]);
		}

		for (int i = 0; i < numCourses; i++)
		{
			if (false == find(graph, i, ret))
				return {};
		}

		reverse(ret.begin(), ret.end());

		return ret;
	}
};

//read solution
//https://leetcode.com/problems/course-schedule-ii/solutions/59316/c-bfs-and-dfs/

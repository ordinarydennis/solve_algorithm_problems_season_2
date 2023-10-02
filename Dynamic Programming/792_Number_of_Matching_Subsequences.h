struct Node
{
	string w;
	int index = 0;
};

class Solution {
public:
	int numMatchingSubseq(string s, vector<string>& words) {

		std::unordered_map<char, vector<Node>> m;

		int ret = 0;

		for (const auto& w: words)
		{
			m[w[0]].emplace_back(Node{ w , 0 });
		}

		for (char c : s)
		{
			auto it = m.find(c);

			if (it == m.end())
			{
				continue;
			}
			
			auto& nodeList = it->second;

			auto temp = nodeList;

			m.erase(it);

			for (auto node : temp)
			{
				node.index++;

				if (node.w.size() <= node.index)
				{
					ret++;
					continue;
				}

				m[node.w[node.index]].push_back(node);
			}
		}

		return ret;
	}
};

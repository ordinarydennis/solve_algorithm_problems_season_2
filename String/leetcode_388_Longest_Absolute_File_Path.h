class Solution {
public:
	int lengthLongestPath(string input) {

		std::map<int, std::vector<string>> vv;

		int tCount = 0;
		int maxtCount = 0;
	
		string s;

		int dir;
		int ret;

		for (int i = 0; i < input.size(); i++)
		{
			if ('\n' == input[i])
			{
				vv[tCount].push_back(s);

				if (maxtCount < tCount)
				{
					dir += (*vv[tCount - 1].rbegin()).size() + s.size();
					maxtCount = tCount;
				}

				ret = max(ret, dir);

				tCount = 0;
			}
			else if ('\t' == input[i])
			{
				tCount++;
			}
			else
			{
				s = input[i];
			}
		}

		return ret;

	}
};



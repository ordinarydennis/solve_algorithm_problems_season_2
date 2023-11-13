class Solution {
public:
	string simplifyPath(string path) {

		string w;

		vector<string> dirList;

		for (int i = 0; i <= path.size(); i++)
		{
			if (i == path.size() || '/' == path[i])
			{
				if (w.size())
				{
					if (".." == w && dirList.size())
					{
						dirList.pop_back();
					}
					else if (".." != w  && "." != w)
					{
						dirList.push_back(w);
					}
					w.clear();
				}
			}
			else
			{
				w += path[i];
			}
		}

		string ret = "/";

		for (int i = 0; i < dirList.size(); i++)
		{
			ret += dirList[i];

			if (i < dirList.size() - 1)
			{
				ret += "/";
			}
		}

		return ret;
	}
};
class Solution {
public:
	string removeDuplicateLetters(string s) {

		std::unordered_map<char, int> m;

		for (int i= 0; i < s.size(); i++)
		{
			m[s[i]] = i;
		}

		std::stack<char> stk;
		std::unordered_map<char, bool> seen;

		for (int i = 0; i < s.size(); i++)
		{
			if (seen[s[i]])
			{
				continue;
			}

			char t = stk.top();
			while ( stk.size() && s[i] < t && i < m[t] )
			{
				seen[t] = false;
				stk.pop();
			}


			stk.push(s[i]);
			seen[s[i]] = true;
		}

		string ret;

		while (stk.size())
		{
			ret += stk.top();
			stk.pop();
		}

		std::reverse(ret.begin(), ret.end());

		return ret;
	}
};
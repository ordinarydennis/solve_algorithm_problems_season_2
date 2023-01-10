class Solution {
public:
	string decodeString(string s) {

		string ss;

		std::stack<int> digitStack;

		std::stack<string> stringStack;

		int index;

		string ret;

		for (int i = 0; i < s.size(); i++)
		{
			if ('1' <= s[i] && s[i] <= '9')
			{
				st.push(s[i]);
			}
			else if ('a' <= s[i] && s[i] <= 'z')
			{
				ss += s[i];
			}
			else if (']' == s[i])
			{
				int n = st.pop();

			}
			else if ('[' == s[i])
			{
				if (ss.size())
				{
					stringStack.push(std::move(ss));
				}
			}
		}
	}

	return ret;
};

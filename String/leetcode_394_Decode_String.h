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

class Solution {
public:
	string decodeString(string s) {

		stack<int> ns;
		stack<string> nstr;

		string base;

		string ret;

		string str;

		for (int i = 0; i < s.size(); i++k)
		{
			char c = s[i];

			if (isdigit(c))
			{
				ns.push(c - '0');

				if (base.size())
				{
					nstr.push(std::move(base));
				}
			}
			else if ('[' == c)
			{
				openCount++;
				
				if (base.size())
				{
					nstr.push(std::move(base));
				}
			}
			else if (']' == c)
			{
				openCount--;

				nstr.push(std::move(base));

				int r = ns.top();
				ns.pop();
				int str = ns.top();
				ns.pop();

				for (int a = 0; a < r - 1; a++)
				{
					str += str;
				}

				base.insert(0, str);

				if (openCount == 0)
				{
					ret += base;
					base.clear();
				}
			}
			else
			{
				base += c;
			}
		}


		return ret;

	}
};
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
		stack<string> chars;
		stack<int> nums;
		string res;
		int num = 0;
		for (char c : s) {
			if (isdigit(c)) {
				num = num * 10 + (c - '0');
			}
			else if (isalpha(c)) {
				res.push_back(c);
			}
			else if (c == '[') {
				chars.push(res);
				nums.push(num);
				res = "";
				num = 0;
			}
			else if (c == ']') {
				string tmp = res;
				for (int i = 0; i < nums.top() - 1; ++i) {
					res += tmp;
				}
				res = chars.top() + res;
				chars.pop(); nums.pop();
			}
		}
		return res;
	}
};

//https://leetcode.com/problems/decode-string/solutions/2927099/easy-solution-short-simple-best-method-easy-to-understand/


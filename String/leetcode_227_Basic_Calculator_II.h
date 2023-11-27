class Solution {
public:
	int calculate(string s) {

		std::stack<char> opS;
		std::stack<char> numS;

		int ret = 0;

		char pop = ' ';

		for (int i = 0; i < s.size(); i++)
		{
			if (' ' == s[i])
			{
				continue;
			}

			if ('+' == s[i] || '-' == s[i])
			{
				opS.push(s[i]);
			}
			else if ('*' == s[i] || '/' == s[i])
			{
				opS.push(s[i]);
				pop = numS.top();
				numS.pop();
			}
			else
			{
				if (' ' != pop)
				{
					char op = opS.top();
					opS.pop();

					if ('*' == op)
					{
						ret += (pop - '0') * (s[i] - '0');
					}
					else
					{
						ret += (pop - '0') / (s[i] - '0');
					}

					pop = ' ';
				}
				else
				{
					numS.push(s[i]);
				}
			}
		}

		if (opS.empty() && numS.size())
		{
			return stoi(s);
		}

		while (false == numS.empty())
		{
			if (false == opS.empty())
			{
				char op = opS.top();

				if ('+' == op)
				{
					ret += numS.top() - '0';
				}
				else if ('-' == op)
				{
					ret -= numS.top() - '0';
				}

				opS.pop();
			}
			else
			{
				ret += numS.top() - '0';
			}

			numS.pop();
		}



		return ret;
	}
};

class Solution {
public:
	int calculate(string s) {

		std::stack<int> stack;

		int num = 0;
		char op = '+';

		int ret = 0;

		for (int i = 0; i <= s.size(); i++)
		{
			char c = s[i];

			if (iswspace(c))
				continue;

			if (i < s.size() && isdigit(c))
			{
				num = (num * 10) + (c - '0');
				continue;
			}

			if ('+' == op)
			{
				stack.push(num);
			}
			else if ('-' == op)
			{
				stack.push(-num);
			}
			else if ('*' == op)
			{
				int preNum = stack.top();
				stack.pop();
				stack.push(preNum * num);
			}
			else
			{
				int preNum = stack.top();
				stack.pop();
				stack.push(preNum / num);
			}

			op = c;
			num = 0;
		}

		while (0 < stack.size())
		{
			ret += stack.top();
			stack.pop();
		}

		return ret;
	}
};

//https://leetcode.com/problems/basic-calculator-ii/editorial/
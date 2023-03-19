class Solution {

	vector<int> ret;

	vector<int> calc(const string& expression, int begin, int end)
	{
		vector<int> r;

		string s;

		for (int i = begin; i < end; i++)
		{
			if ('*' == expression[i] || '-' == expression[i] || '+' == expression[i])
			{
				auto llist = calc(expression, begin, i);
				auto rlist = calc(expression, i + 1, end);

				for (auto ln : llist)
				{
					for (auto rn : rlist)
					{
						if ('*' == expression[i])
						{
							r.push_back(ln * rn);
						}
						else if ('-' == expression[i])
						{
							r.push_back(ln - rn);
						}
						else
						{
							r.push_back(ln + rn);
						}
					}
				}
			}
			else
			{
				s.push_back(expression[i]);
			}
		}

		if (r.empty())
		{
			return vector<int> { stoi(s) };
		}
		
		return r;
	}


public:
	vector<int> diffWaysToCompute(string expression) {

		return calc(expression, 0, expression.size());

	}
};

//https://leetcode.com/problems/different-ways-to-add-parentheses/solutions/66331/c-4ms-recursive-dp-solution-with-brief-explanation/?orderBy=most_votes


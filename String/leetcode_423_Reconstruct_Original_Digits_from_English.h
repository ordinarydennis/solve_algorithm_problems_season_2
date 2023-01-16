class Solution {

	bool checkNum(const string& num, string& s)
	{
		vector<char> charList;

		bool findAll = true;

		for (char c : num)
		{
			int i = s.find(c);

			if (string::npos == i)
			{
				findAll = false;
				break;
			}

			charList.push_back(c);
		}

		if (findAll)
		{
			for (char c : charList)
			{
				int i = s.find(c);;
				s.erase(i, 1);
			}
		}

		return findAll;
	}

public:
	string originalDigits(string s) {

		string ret;

		while (s.size())
		{
			if (checkNum("zero", s))
			{
				ret += '0';
			}

			if (checkNum("one", s))
			{
				ret += '1';
			}
			if (checkNum("two", s))
			{
				ret += '2';
			}
			if (checkNum("three", s))
			{
				ret += '3';
			}
			if (checkNum("four", s))
			{
				ret += '4';
			}
			if (checkNum("five", s))
			{
				ret += '5';
			}
			if (checkNum("six", s))
			{
				ret += '6';

			}
			if (checkNum("seven", s))
			{
				ret += '7';

			}
			if (checkNum("eight", s))
			{
				ret += '8';

			}
			if (checkNum("nine", s))
			{
				ret += '9';
			}
		}


		return ret;
	}
};
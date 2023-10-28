class Solution {

	vector<string> ret;

	void dfs(string& digits, int index, std::unordered_map<int, string>&  map, const string& str)
	{
		if (digits.size() <= index)
		{
			ret.push_back(str);
			return;
		}

		//char to int
		const auto& s = map[static_cast<int>(digits[index] - '0')];

		for (int i = 0; i < s.size(); i++)
		{
			dfs(digits, index + 1, map, str + s[i]);
		}
	}

public:
	vector<string> letterCombinations(string digits) {

		if (digits.empty())
			return ret;

		std::unordered_map<int, string> map {
			{ 2, "abc"  },
			{ 3, "def"  },
			{ 4, "ghi"  },
			{ 5, "jkl"  },
			{ 6, "mno"  },
			{ 7, "qprs" },
			{ 8, "tuv"  },
			{ 9, "wxyz" }
		};

		dfs(digits, 0, map, "");

		return ret;
	}
};


class Solution {

	std::unordered_map<char, string> pad = {
		{ '2', "abc"  },
		{ '3', "def"  },
		{ '4', "ghi"  },
		{ '5', "jkl"  },
		{ '6', "mno"  },
		{ '7', "qprs" },
		{ '8', "tuv"  },
		{ '9', "wxyz" }
	};

	void dfs(string& digits, int index, string& s, vector<string>& ret)
	{
		if (digits.size() <= index)
		{
			ret.push_back(s);
		}

		const auto& str = pad[digits[index]];

		for (char c : str)
		{
			s.push_back(c);

			dfs(digits, index + 1, s, ret);

			s.pop_back();
		}
	}


public:
	vector<string> letterCombinations(string digits) {

		if (digits.empty()) return {};

		vector<string> ret;

		string s;

		dfs(digits, 0, s, ret);

		return ret;
	}
};

//https://leetcode.com/problems/letter-combinations-of-a-phone-number/solutions/3222449/best-c-2-solution-backtracking-iterative-recursive-one-stop-solution/
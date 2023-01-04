class Solution {
public:
	string removeDuplicateLetters(string s) {

		std::set<char> cs;

		string ret;

		for (char c : s)
		{
			cs.insert(c);
		}

		ret.reserve(cs.size());

		for (char c : cs)
		{
			ret.push_back(c);
		}

		return ret;
	}
};
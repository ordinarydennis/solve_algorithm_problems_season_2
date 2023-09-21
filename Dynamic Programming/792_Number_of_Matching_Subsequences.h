class Solution {

	int ret = 0;

	void dfs(string& word, int wIndex, string& s, int sIndex)
	{
		if (wIndex <= word.size())
		{
			ret++;
			return;
		}

		for (int i = sIndex; i < s.size(); i++)
		{
			if (s[i] == word[wIndex])
			{
				dfs(word, i + 1, s, sIndex + 1);
			}
		}

	}

public:
	int numMatchingSubseq(string s, vector<string>& words) {

		for (auto& word : words)
		{
			dfs(word, 0, s, 0);
		}

		return ret;
	}
};
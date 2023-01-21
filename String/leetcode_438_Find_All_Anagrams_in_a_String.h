class Solution {
public:
	vector<int> findAnagrams(string s, string p) {

		if (s.size() < p.size())
		{
			return {};
		}

		int alphabetCount = 'z' - 'a' + 1;

		std::vector<int> phash(alphabetCount, 0);
		std::vector<int> shash(alphabetCount, 0);

		for (int i = 0; i < p.size(); i++)
		{
			phash[p[i] - 'a']++;
			shash[s[i] - 'a']++;
		}

		std::vector<int> ret;

		int left = 0;
		int right = p.size();
	
		while(left <= s.size() - p.size())
		{
			if (phash == shash)
			{
				ret.push_back(left);
			}

			if (left == s.size() - p.size())
			{
				break;
			}

			shash[s[right] - 'a']++;
			shash[s[left] - 'a']--;

			right++;
			left++;
		}

		return ret;

	}
};
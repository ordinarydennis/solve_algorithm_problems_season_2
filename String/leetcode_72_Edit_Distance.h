class Solution {
public:
	int minDistance(string word1, string word2) {

		int index1 = 0;
		int index2 = 0;

		int ret = 0;

		while (index1 < word1.size())
		{
			if (word1[index1] != word2[index2])
			{
				if (word2.size() <= word1.size())
				{
					if (word1[index1 + 1] == word2[index2])
					{
						word1.erase(index1);
	
					}
					else
					{
						word1[index1] = word2[index2];
					}
				}
				else
				{
					word1.insert(word1.begin() + index1, word2[index2]);
					index1++;
				}
				ret++;
			}

			index1++;
			index2++;
		}

		cout << word1 << endl;

		return ret;
	}
};
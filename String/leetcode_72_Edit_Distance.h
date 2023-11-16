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

class Solution {
public:
	int minDistance(string word1, string word2) {
		const int m = word1.length();//first word length
		const int n = word2.length();//second word length
		// dp[i][j] := min # of operations to convert word1[0..i) to word2[0..j)
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));

		for (int i = 1; i <= m; ++i)
			dp[i][0] = i;

		for (int j = 1; j <= n; ++j)
			dp[0][j] = j;

		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				if (word1[i - 1] == word2[j - 1])//same characters
					dp[i][j] = dp[i - 1][j - 1];//no operation
				else
				{
					dp[i][j] = min(
						{ 
							dp[i - 1][j - 1], 
							dp[i - 1][j], 
							dp[i][j - 1] 
						}
					) + 1;
				}

		//replace       //delete        //insert
		return dp[m][n];
	}
};

//https://leetcode.com/problems/edit-distance/solutions/3230662/clean-codes-full-explanation-dynamic-programming-c-java-python3/
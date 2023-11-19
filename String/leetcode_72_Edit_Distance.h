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


class Solution {
public:
	int minDistance(string word1, string word2) {

		vector<vector<int>> matrix(word1.size() + 1, vector<int>(word2.size() + 1));

		for (int i = 0; i <= word1.size(); i++)
		{
			matrix[i][0] = i;
		}

		for (int i = 0; i <= word2.size(); i++)
		{
			matrix[0][i] = i;
		}

		for (int a = 0; a < word1.size(); a++)
		{
			for (int b = 0; b < word2.size(); b++)
			{
				if (word1[a] != word2[b])
				{
					matrix[a + 1][b + 1] = std::min(
						{
							matrix[a + 1][b],
							matrix[a][b + 1],
							matrix[a][b],
						}
					) + 1;
				}
				else
				{
					matrix[a + 1][b + 1] = matrix[a][b];
				}
			}
		}

		return matrix[word1.size()][word2.size()];
	}
};

https://jino-dev-diary.tistory.com/entry/Algorithm-%EB%AC%B8%EC%9E%A5%EC%9D%98-%EC%9C%A0%EC%82%AC%EB%8F%84-%EB%B6%84%EC%84%9D-%ED%8E%B8%EC%A7%91-%EA%B1%B0%EB%A6%AC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Levenshtein-Distance
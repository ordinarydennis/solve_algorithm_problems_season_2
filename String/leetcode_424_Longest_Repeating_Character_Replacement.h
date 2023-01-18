class Solution {

public:
	int characterReplacement(string s, int k) {

		int max = INT_MIN;

		for (int i = 0; i < s.size() - 1; i++)
		{
			char c = s[i];
			int count = 1;
			int kk = k;

			for (int a = i + 1; a < s.size(); a++)
			{
				if (c == s[a])
				{
					count++;
				}
				else
				{
					if (kk)
					{
						kk--;
						count++;
					}
					else
					{
						break;
					}
				}
			}

			if (0 == kk || 0 == i)
			{
				max = std::max(max, count);
				continue;
			}

			for (int a = i - 1; 0 < a; a--)
			{
				if (c == s[a])
				{
					count++;
				}
				else
				{
					if (kk)
					{
						kk--;
						count++;
					}
					else
					{
						break;
					}
				}
			}
			max = std::max(max, count);

		}
		return max;
	}
};


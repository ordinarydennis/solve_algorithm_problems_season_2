class Solution {
public:
	int lengthLongestPath(string input) {

		input.push_back('\n');

		vector<int> levels(300, 0);

		int level = 0;

		bool isFile = false;

		int ans = 0;

		int length = 0;

		for (char c : input)
		{
			switch (c)
			{
			case '\n':
			{
				level = 0;
				length = 0;
				isFile = false;
				break;
			}
			case '\t':
			{
				level++;
				break;
			}
			case '.':
				isFile = true;

			default:
				length++;
				levels[level] = length;
				if (isFile)
				{
					ans = max(ans, accumulate(levels.begin(), levels.begin() + level + 1, 0) + level);
				}
			}
		}

		return ans;
	}
};

//Elegant C++ Solution without stack
//https://leetcode.com/problems/longest-absolute-file-path/solutions/290430/elegant-c-solution-without-stack/

//C++ O(n) Solution with hashmap
//https://leetcode.com/problems/longest-absolute-file-path/solutions/86821/c-o-n-solution-with-hashmap/?orderBy=most_votes
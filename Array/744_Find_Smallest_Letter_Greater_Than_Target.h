class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {

		int s = 0;

		for (int i = 0; i < letters.size(); i++)
		{
			if (target < letters[i])
			{
				s = i;
				break;
			}
		}

		return letters[s];
	}
};
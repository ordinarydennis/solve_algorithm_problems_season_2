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

class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {

		int low = 0;
		int high = letters.size() - 1;

		if (letters[low] > target)
		{
			return letters[low];
		}
		
		if (letters[high] < target)
		{
			return letters[low];
		}
		
		while (low < high) {

			int mid = (low + high) / 2;

			if (letters[mid] <= target)
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}
		return letters[low] > target ? letters[low] : letters[0];
	}
};

//https://leetcode.com/problems/find-smallest-letter-greater-than-target/solutions/760959/c-3-approaches-easy-to-understand/
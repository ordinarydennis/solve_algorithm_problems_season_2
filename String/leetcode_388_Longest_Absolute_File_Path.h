class Solution {
public:
	int lengthLongestPath(string input) {

		std::vector<int> v(input.size(), 0);

		v[0] = 3;

		int tcount = 0;

		int length = 0;

		int max = 0; 

		bool dot = false;

		for (int i = 3; i < input.size(); i++)
		{
			char c = input[i];

			if ('\n' == c)
			{
				continue;
			}

			if ('\t' == c)
			{
				v[tcount] = length;
				tcount++;
			}
			else if ('.' == c)
			{
				int sum = 0;

				std::max(max, length + 3);
				length + 3;

				length = 0;
				tcount = 0;

			}
			else
			{
				if(tcount)
				{ 
					length += v[tcount - 1] + 1;
				}

				length++;
			}
		}

	}
};
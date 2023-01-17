class Solution {

public:
	string originalDigits(string s) {

		std::vector<int> count(10, 0);

		for (char c : s)
		{
			if ('z' == c)
				count[0]++;
			else if ('w' == c)
				count[2]++;
			else if('h' == c)
				count[3]++;
			else if('u' == c)
				count[4]++;
			else if('g' == c)
				count[8]++;
			else if('x' == c)
				count[6]++;
			else if ('f' == c)
				count[5]++;
			else if ('s' == c)
				count[7]++;
			else if ('i' == c)
				count[9]++;
			else if ('o' == c)
				count[1]++;
		}

		count[3] -= count[8];
		count[5] -= count[4];
		count[7] -= count[6];
		count[9] -= count[8] + count[6] + count[5];
		count[1] -= count[4] + count[2] + count[0];

		string ret;

		for (int i = 0; i < count.size(); i++)
		{
			if (count[i] <= 0)
				continue;

			for (int a = 0; a < count[i]; a++)
			{
				ret += i + '0';
			}
		}

		return ret;
	}
};

//zero z
//two w
//four u
//eight g
//six x

//three // h count - g count(8)
//five  // f count - u count(4)
//seven // s count - x count(6)

//nine // i count - f count(5) - x count(6) - g count(8)
//one  // one - four - two - zero //o

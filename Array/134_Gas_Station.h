class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int ret = -1;

		int size = gas.size();

		for (int i = 0; i < size; i++)
		{
			int acount = 0;

			int a = i;

			int count = 0;

			while (count < size)
			{
				int index = (a) % gas.size();

				acount += gas[index] - cost[index];

				if (acount < 0)
				{
					break;
				}

				count++;
				a++;
			}

			if (count == size && 0 <= acount)
			{
				ret = i;
				break;
			}
		}

		return ret;
	}
};

https://leetcode.com/problems/gas-station/solutions/1706142/java-c-python-an-explanation-that-ever-exists-till-now/?orderBy=most_votes

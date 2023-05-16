class Solution {
public:
	//brute force
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int size = gas.size();

		for (int i = 0; i < size; i++)
		{
			int total = 0;
			int index = i;
			int count = size;

			while (count)
			{
				total += gas[index % size] - cost[index % size];
				count--;
				index++;

				if (total <= 0)
				{
					break;
				}
			}

			if (0 == count && 0 <= total)
			{
				return i;
			}
		}

		return -1;
	}
};

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int total = 0;
		int positionTotal = 0;
		int index = 0;

		for (int i = 0; i < gas.size(); i++)
		{
			total += gas[i] - cost[i];
			
			positionTotal += gas[i] - cost[i];

			if (positionTotal < 0)
			{
				positionTotal = 0;
				index = i + 1;
			}
		}

		return (0 <= total) ? index : -1;
	}
};

https://leetcode.com/problems/gas-station/solutions/1706142/java-c-python-an-explanation-that-ever-exists-till-now/?orderBy=most_votes



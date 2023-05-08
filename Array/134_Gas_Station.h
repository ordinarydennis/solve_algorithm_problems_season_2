class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int ret = -1;

		for (int i = 0; i < gas.size(); i++)
		{
			int acount = 0;

			for (int a = 0; a < gas.size(); a++)
			{
				int pos = (i + a) % gas.size();

				acount += gas[pos];

				if (0 < a)
				{
					int pos2 = (i + a - 1) % gas.size();
					acount -= cost[pos2];
				}
				
				if (acount <= 0)
				{
					break;
				}
			}

			if (0 < acount)
			{
				ret = i;
				break;
			}
		}


		return ret;
	}
};
class Solution {
public:
	string multiply(string num1, string num2) {

		double sum = 0;

		double d1 = 1;

		for (int a = num1.size() - 1; 0 <= a; a--)
		{
			double n1 = (num1[a] - '0') * d1;

			double d2 = 1;

			for (int b = num2.size() - 1; 0 <= b; b--)
			{
				double n2 = num2[b] - '0';
				sum += (n1 * n2) * d2;
				d2 *= 10;
			}

			d1 *= 10;
		}

		string ret = to_string(sum);

		string ret2;

		for (int i = 0; i < ret.size(); i++)
		{
			if ('.' == ret[i])
			{
				break;
			}

			ret2 += ret[i];
			
		}

		return ret2;
	}
};

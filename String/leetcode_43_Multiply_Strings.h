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
			}r

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


class Solution {
public:
	string multiply(string num1, string num2) {
		// handle edge-case where the product is 0
		if (num1 == "0" || num2 == "0") return "0";

		// num1.size() + num2.size() == max no. of digits
		vector<int> num(num1.size() + num2.size(), 0);

		// build the number by multiplying one digit at the time
		for (int i = num1.size() - 1; i >= 0; --i) {
			for (int j = num2.size() - 1; j >= 0; --j) {
				num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
				num[i + j] += num[i + j + 1] / 10;
				num[i + j + 1] %= 10;
			}
		}

		// skip leading 0's
		int i = 0;
		while (i < num.size() && num[i] == 0) ++i;

		// transofrm the vector to a string
		string res = "";
		while (i < num.size()) res.push_back(num[i++] + '0');

		return res;
	}
};

//https://leetcode.com/problems/multiply-strings/solutions/563504/simple-c-solution-with-comments-94-86-faster-100-memory/

//my solution
class Solution {
public:
	string multiply(string num1, string num2) {

		map<int, int> m;

		int c = 0;

		for (int a = num1.size() - 1; 0 <= a; a--)
		{
			int t = c;
			for (int b = num2.size() - 1; 0 <= b; b--)
			{
				int multi = (num1[a] - '0') * (num2[b] - '0');

				m[t] += (multi) % 10;
				m[t + 1] += (multi) / 10;
				t++;
			}
			c++;
		}

		string ret;

		for (auto it = m.rbegin(); it != m.rend(); ++it)
		{
			if (it->second)
				ret += it->second + '0';
		}

		return  ret;
	}
};
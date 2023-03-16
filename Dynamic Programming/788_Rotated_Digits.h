class Solution {
public:
	int rotatedDigits(int n) {

		int ret = 0;

		for (int i = 1; i <= n; i++)
		{
			if (i < 10)
			{
				if (1 == i || 3 ==i || 4 == i || 7 ==i || 8 == i)
				{
					continue;
				}
				else
				{
					ret++;
				}
			}
			else
			{
				string ns = to_string(i);

				if ('0' == ns.back())
				{
					continue;
				}

				int start = 0;
				int end = ns.size() - 1;

				while (start < end)
				{
					char t = ns[start];
					ns[start] = ns[end];
					ns[end] = t;
					start++;
					end--;
				}

				string base = to_string(i);

				if (base == ns)
				{
					continue;
				}

				bool isFail = false;

				for (int i = 0; i < ns.size(); i++)
				{
					if ('3' == ns[i] || '4' == ns[i] || '7' == ns[i])
					{
						isFail = true;
						break;
					}
				}

				if (false == isFail)
				{
					cout << ns << ",";
					ret++;
				}
			}
		}

		return ret;
	}
};


class Solution {
public:
	int rotatedDigits(int n) {

		int res = 0;

		for (int i = 1; i <= n; i++) {

			int p = i;
			
			int s = 1;
			
			while (p)
			{
				s *= f[p % 10];
				p /= 10;
			}

			if (s >= 2)
				res += 1;

		}
		return res;


		return ret;
	}
};

public int rotatedDigits(int N) {
	
	int[] dp = new int[N + 1];
	
	int count = 0;

	for (int i = 0; i <= N; i++) {

		if (i < 10)
		{
			if (i == 0 || i == 1 || i == 8)
			{
				dp[i] = 1;
			}
			else if (i == 2 || i == 5 || i == 6 || i == 9)
			{
				dp[i] = 2;
				count++;
			}
		}
		else {
			int a = dp[i / 10], b = dp[i % 10];
			if (a == 1 && b == 1) 
				dp[i] = 1;
			else if (a >= 1 && b >= 1)
			{
				dp[i] = 2;
				count++;
			}
		}
	}
	return count;
}
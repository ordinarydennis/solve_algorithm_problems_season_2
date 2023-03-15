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
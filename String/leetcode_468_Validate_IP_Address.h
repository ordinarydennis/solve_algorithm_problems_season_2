class Solution {

	bool isIPv4(const string& queryIP)
	{
		for (char c : queryIP)
		{
			if ('.' == c)
			{
				return true;
			}

			if (':' == c)
			{
				return false;
			}
		}

		return false;

	}

	bool checkIPv4(const string& queryIP)
	{
		string s;

		int count = 0;

		for (int i = 0; i <= queryIP.size(); i++)
		{
			if (i == queryIP.size() || '.' == queryIP[i])
			{
				if ('.' == queryIP[i])
				{
					count++;
				}

				if (s.empty())
				{
					return false;
				}

				if (1 < s.size() && '0' == s[0])
				{
					return false;
				}

				for (char c : s)
				{
					if ('a' <= c && c <= 'f' || 'A' <= c && c <= 'F')
					{
						return false;
					}
				}

				int n = std::atoi(s.c_str());

				if (255 < n)
				{
					return false;
				}

				s.clear();
			}
			else
			{
				s += queryIP[i];
				if (3 < s.size())
				{
					return false;
				}
			}
		}

		if (3 != count)
		{
			return false;
		}

		return true;
	}

	bool checkIPv6(const string& queryIP)
	{
		string s;

		int count = 0;

		for (int i = 0; i <= queryIP.size(); i++)
		{
			if (i == queryIP.size() || ':' == queryIP[i])
			{
				if (':' == queryIP[i])
				{
					count++;
				}
				if (s.empty())
				{
					return false;
				}

				if (4 < s.size())
				{
					return false;
				}

				for (char c : s)
				{
					if ('0' <= c && c <= '9' || 'a' <= c && c <= 'f' || 'A' <= c && c <= 'F')
					{
						//true;
					}
					else
					{
						return false;
					}
				}

				s.clear();
			}
			else
			{
				s += queryIP[i];
				if (4 < s.size())
				{
					return false;
				}
			}
		}

		if (7 != count)
		{
			return false;
		}

		return true;
	}

public:
	string validIPAddress(string queryIP) {

		if (isIPv4(queryIP))
		{
			if (checkIPv4(queryIP))
			{
				return "IPv4";
			}
		}
		else
		{
			if (checkIPv6(queryIP))
			{
				return "IPv6";
			}
		}

		return "Neither";
	}
};
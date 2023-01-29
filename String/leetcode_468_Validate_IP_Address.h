class Solution {

	int IsIPv4(const string& str)
	{
		return count(str.begin(), str.end(), '.');
	}

	string CheckValidIPv4(const string& ip)
	{
		if (count(ip.begin(), ip.end(), '.') > 3)
		{
			return "Neither";
		}

		auto strList = split(ip, '.');

		if (4 != strList.size())
		{
			return "Neither";
		}

		for (int i = 0; i < strList.size(); i++)
		{
			const auto& str = strList[i];

			if (str.size() > 3 || str.empty())
			{
				return "Neither";
			}

			if (1 < str.size() && '0' == str[0])
			{
				return "Neither";
			}

			for (char c : str)
			{
				if (false == isdigit(c))
				{
					return "Neither";
				}
			}

			if (255 < std::stoi(str))
			{
				return "Neither";
			}
		}

		return "IPv4";
	}

	string CheckValidIPv6(const string& ip)
	{
		auto strList = split(ip, ':');

		if (count(ip.begin(), ip.end(), ':') > 7)
		{
			return "Neither";
		}

		if (strList.size() != 8)
		{
			return "Neither";
		}

		for (int i = 0; i < strList.size(); i++)
		{
			const string str = strList[i];

			if (str.size() > 4 || str.empty())
			{
				return "Neither";
			}

			for (char c : str)
			{
				if (isdigit(c) && isalpha(c))
				{
					return "Neither";
				}

				if (isalpha(c) && toupper(c) > 'F')
				{
					return "Neither";
				}
			}
		}

		return "IPv6";
	}

	vector<string> split(const string& str, char deli)
	{
		vector<string> ret;

		istringstream in(str);

		string s;

		while (getline(in, s, deli))
		{
			ret.push_back(s);
		}

		return ret;
	}


public:
	string validIPAddress(string IP) {

		return IsIPv4(IP) ? CheckValidIPv4(IP) : CheckValidIPv6(IP);

	}
};

//refer to link blow
//https://leetcode.com/problems/validate-ip-address/solutions/238511/c-split/

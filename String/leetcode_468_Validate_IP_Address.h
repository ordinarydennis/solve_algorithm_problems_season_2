https://leetcode.com/problems/validate-ip-address/solutions/689995/c-regex-solution-4-lines-of-code-time-space-o-1-beats-100/?orderBy=most_votes
class Solution {
public:
	string validIPAddress(string IP) {
		regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
		regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4}");   // create regex object for regulare expression
		
		if (regex_match(IP, ipv4)) // match regex expression with given IP string for IPv4
			return "IPv4";
		else if (regex_match(IP, ipv6)) // match regex expression with given IP string for IPv6
			return "IPv6";
		return "Neither"; // Otherwise return "Neither"
	}
};

https://leetcode.com/problems/validate-ip-address/solutions/95552/my-straightforward-c-solution/?orderBy=most_votes
class Solution {
public:
	string validIPAddress(string IP) {
		istringstream is(IP);
		string t = "";
		int cnt = 0;
		if (IP.find(':') == string::npos) { // Check IPv4
			while (getline(is, t, '.')) {
				++cnt;
				if (cnt > 4 || t.empty() || (t.size() > 1 && t[0] == '0') || t.size() > 3) return "Neither";
				for (char c : t) {
					if (c < '0' || c > '9') return "Neither";
				}
				int val = stoi(t);
				if (val < 0 || val > 255) return "Neither";
			}
			return (cnt == 4 && IP.back() != '.') ? "IPv4" : "Neither";
		}
		else { // Check IPv6
			while (getline(is, t, ':')) {
				++cnt;
				if (cnt > 8 || t.empty() || t.size() > 4) return "Neither";
				for (char c : t) {
					if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return "Neither";
				}
			}
			return (cnt == 8 && IP.back() != ':') ? "IPv6" : "Neither";
		}
	}
};
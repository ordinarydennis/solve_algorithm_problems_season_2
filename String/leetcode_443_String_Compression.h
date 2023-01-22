class Solution {
public:
	int compress(vector<char>& chars) {

		char prec = chars[0];

		vector<char> chars2;

		int count = 1;

		int ret = 0;

		for (int i = 1; i <= chars.size(); i++)
		{
			if (i < chars.size() && prec == chars[i])
			{
				count++;
			}
			else
			{
				chars2.push_back(prec);

				if (1 < count)
				{
					int count2 = count;

					count = 1;

					vector<char> nlist;

					while (count2)
					{
						count++;

						int n = count2 % 10;

						nlist.push_back('0' + n);

						count2 = count2 / 10;
					}

					std::reverse(nlist.begin(), nlist.end());

					chars2.insert(chars2.end(), nlist.begin(), nlist.end());
				}

				ret += count;

				if (i < chars.size())
				{
					prec = chars[i];
					count = 1;
				}

			}
		}

		chars = std::move(chars2);

		return ret;

	}
};
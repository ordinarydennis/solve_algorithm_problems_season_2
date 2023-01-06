class Solution {
public:
	int maxProduct(vector<string>& words) {

		int max = INT_MIN;

		for (int a = 0; a < words.size() - 1; a++)
		{
			for (int b = a + 1; b < words.size(); b++)
			{
				string ls;
				string ss;

				if (words[a].size() < words[b].size())
				{
					ls = words[b];
					ss = words[a];
				}
				else
				{
					ls = words[a];
					ss = words[b];
				}

				int discount = 0;

				bool isFail = false;

				for (int i = 0; i < ls.size();)
				{
					int index = ss.find(ls[i]);

					if (string::npos != index)
					{
						discount++;

						ss.erase(index, 1);
						ls.erase(index, 1);

						if (0 == ss.size())
						{
							isFail = true;
							break;
						}
					}
					else
					{
						i++;
					}
				}

				if (isFail)
				{
					break;
				}

				int m = ss.size() * ls.size();

				if (max < m)
				{
					max = m;
					std::cout << ss << " " << ls << std::endl;
				}

			}
		}

		return max;
	}
};
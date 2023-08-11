class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

		std::unordered_map<char, int> m;

		for (int i = 0; i < order.size(); i++)
		{
			m.emplace(order[i], i);
		}

		for (int a = 0; a < words.size() - 1; a++)
		{
			for (int b = a + 1; b < words.size(); b++)
			{
				int i = 0;
				
				bool isAl = false;

				while (i < words[a].size() && i < words[b].size())
				{
					if (m[words[a][i]] > m[words[b][i]])
					{
						return false;
					}
					else if(m[words[a][i]] == m[words[b][i]])
					{

					}
					else
					{
						isAl = true;
						break;
					}
					i++;
				}

				if (false == isAl && words[b].size() < words[a].size())
				{
					return false;
				}

			}
		}

		return true;
        
    }
};
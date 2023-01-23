class Solution {
public:
	int compress(vector<char>& chars) {

		int index = 0;
		int wIndex = 0;

		while (index < chars.size())
		{
			char prec = chars[index];
			
			int count = 0;

			while(index < chars.size() && prec == chars[index])
			{
				count++;
				index++;
			}
			
			chars[wIndex++] = prec;

			if (1 < count)
			{
				string cs = std::to_string(count);

				for (char c : cs)
				{
					chars[wIndex++] = c;
				}
			}
		}

		return wIndex;
	}
};

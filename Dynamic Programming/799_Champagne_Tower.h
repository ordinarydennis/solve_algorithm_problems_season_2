class Solution {
public:
	double champagneTower(int poured, int query_row, int query_glass) {

		std::vector<double> cur(1, poured);

		for (int i = 0; i <= query_row; i++)
		{
			std::vector<double> next(i + 2, 0);

			for (int a = 0; a <= i; a++)
			{
				if (1 <= cur[a])
				{
					next[a] += (cur[a] - 1) / 2.0;
					next[a + 1] += (cur[a] - 1) / 2.0;
					cur[a] = 1;
				}
			}

			if (i != query_row)
			{
				cur = next;
			}
		}

		return cur[query_glass];

	}
};
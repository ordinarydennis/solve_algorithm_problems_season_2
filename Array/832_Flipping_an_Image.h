class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

		for (auto& v : image)
		{
			int b = 0;
			int e = v.size() - 1;

			while (b < e)
			{
				std::swap(v[b], v[e]);

				v[b] = (0 < v[b]) ? 0 : 1;
				v[e] = (0 < v[e]) ? 0 : 1;

				b++;
				e--;
			}

			if (b == e)
			{
				v[b] = (0 < v[b]) ? 0 : 1;
			}
		}

		return image;

	}
};
class Solution {
public:
	int maxArea(vector<int>& height) {

		int size = static_cast<int>(height.size());

		int ret = 0;

		for (int a = 0; a < size - 1; a++)
		{
			for (int b = a + 1; b < size; b++)
			{
				int h = std::min(height[a], height[b]);
				ret = std::max(ret, h * (b - a));
				m = h;
			}
		}

		return ret;
	}
};
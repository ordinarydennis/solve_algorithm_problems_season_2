
//first approch(time limit)
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


//two point
class Solution {
public:
	int maxArea(vector<int>& height) {

		int l = 0;

		int r = static_cast<int>(height.size() - 1);

		int ret = 0;

		while (l < r)
		{
			int h = std::min(height[l], height[r]);

			ret = std::max(ret, h * (r - l));

			if (height[l] < height[r])
			{
				l++;
			}
			else
			{
				r--;
			}
		}

		return ret;
	}
};

class Solution {
public:
	int maxArea(vector<int>& height) {

		int l = 0;
		int r = height.size() - 1;

		int ret = 0;

		while (l < r)
		{
			int h = std::min(height[r], height[l]);

			ret = std::max(ret, h * (r - l));

			if (height[r] < height[l])
			{
				r--;
			}
			else
			{
				l++;
			}
		}

		return ret;
	}
};

class Solution {
public:
	int maxArea(vector<int>& height) {

		int max = height.size() - 1;

		int l = 0;

		int r = max;

		int ret = 0;

		while (l <r)
		{
			int h = std::min(height[l], height[r]);

			ret = std::max(ret, h * (r - l));

			if (height[l] < height[r])
			{
				l++;
			}
			else
			{
				r--;
			}
		}

		return ret;

	}
};
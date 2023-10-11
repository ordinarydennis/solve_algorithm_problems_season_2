class Solution {
public:
	int longestMountain(vector<int>& arr) {

		int max = static_cast<int>(arr.size());

		int start = 0;
		int end = 0;

		int ret = 0;

		while (start < max)
		{
			end = start;

			if (end + 1 < max && arr[end] < arr[end + 1])
			{
				while (end + 1 < max && arr[end] < arr[end + 1]) end++;

				if (end + 1 < max && arr[end] > arr[end + 1])
				{
					while (end + 1 < max && arr[end] > arr[end + 1]) end++;

					ret = std::max(ret, end - start + 1);
				}
			}

			start = std::max(end, start + 1);
		}

		return ret;
	}
};
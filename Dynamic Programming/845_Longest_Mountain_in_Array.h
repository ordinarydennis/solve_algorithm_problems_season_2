class Solution {
public:
	int longestMountain(vector<int>& arr) {

		int start = 0;
		int max = static_cast<int>(arr.size());

		int ret = 0;

		while (start < max)
		{
			int end = start;

			if (end + 1 < max && arr[end] < arr[end + 1])
			{
				while (end + 1 < arr.size() && arr[end] < arr[end + 1])
				{
					end++;
				}

				if (end + 1 < max && arr[end] > arr[end + 1])
				{
					while (end + 1 < max && arr[end] > arr[end + 1])
					{
						end++;
					}
					ret = std::max(ret, end - start + 1);
				}
			}

			start = std::max(start + 1, end);
		}

		return ret;
	}
};
class Solution {
public:
	int findLength(vector<int>& nums1, vector<int>& nums2) {

		vector<int>& first = nums1;
		vector<int>& second = nums2;

		if (nums2.size() < nums1.size())
		{
			first = nums2;
			second = nums1;
		}

		int ret = 0;

		for (int a = 0; a < first.size(); a++)
		{
			for (int b = 0; b < second.size(); b++)
			{
				if (first[a] != second[b])
				{
					continue;
				}

				int count = 0;

				int aa = a;
				int bb = b;

				while (bb < second.size() && aa < first.size() && first[aa] == second[bb])
				{
					count++;
					aa++;
					bb++;
				}

				ret = std::max(ret, count);
			}
		}

		return ret;
	}
};
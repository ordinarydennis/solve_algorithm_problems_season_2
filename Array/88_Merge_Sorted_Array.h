class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		int index1 = 0;
		int index2 = 0;

		vector<int> nums;

		while (index1 < m || index2 < n)
		{
			int n1 = INT_MAX;
			int n2 = INT_MAX;

			if (index1 < m)
			{
				n1 = nums1[index1];
			}

			if (index2 < n)
			{
				n2 = nums2[index2];
			}

			if (n1 <= n2)
			{
				nums.push_back(n1);
				index1++;
			}
			else
			{
				nums.push_back(n2);
				index2++;
			}
		}

		nums1 = std::move(nums);

	}
};
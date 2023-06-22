class Solution {
public:
	int dominantIndex(vector<int>& nums) {

		int max = 0;
		int max_second = 0;

		int index = -1;

		for (int i = 0; i < nums.size(); i++)
		{
			if(max < nums[i])
			{
				max_second = max;
				max = nums[i];
				index = i;
			}
			else if (max_second < nums[i])
			{
				max_second = nums[i];
			}
		}

		return (max_second * 2 <= max) ? index : -1;
	}
};

class Solution {
public:
	bool isMonotonic(vector<int>& nums) {

	
		bool isCheck = false;
		bool isIncr = true;

		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] == nums[i + 1])
			{
				continue;
			}

			if (false == isCheck)
			{
				if (nums[i] > nums[i + 1])
				{
					isIncr = false;
				}
				isCheck = true;
			}
			else if (isIncr)
			{
				if (nums[i] > nums[i + 1])
				{
					return false;
				}
			}
			else
			{
				if (nums[i] < nums[i + 1])
				{
					return false;
				}
			}

		}

		return true;
	}
};
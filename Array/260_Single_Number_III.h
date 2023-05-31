class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {

		std::unordered_set<int> s;

		for (int i = 0; i < nums.size(); i++)
		{
			if (s.count(nums[i]))
			{
				s.erase(nums[i]);
			}
			else
			{
				s.insert(nums[i]);
			}
		}

		vector<int> ret;

		for (int e : s)
		{
			ret.push_back(e);
		}

		return ret;

	}
	
};


class Solution
{
public:
	vector<int> singleNumber(vector<int>& nums)
	{
		// Pass 1 : 
		// Get the XOR of the two numbers we need to find
		int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
		// Get its last set bit
		diff &= -diff;

		// Pass 2 :
		vector<int> rets = { 0, 0 }; // this vector stores the two numbers we will return
		for (int num : nums)
		{
			if ((num & diff) == 0) // the bit is not set
			{
				rets[0] ^= num;
			}
			else // the bit is set
			{
				rets[1] ^= num;
			}
		}
		return rets;
	}
};

//https://leetcode.com/problems/single-number-iii/solutions/68900/accepted-c-java-o-n-time-o-1-space-easy-solution-with-detail-explanations/
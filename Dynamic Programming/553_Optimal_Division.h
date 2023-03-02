// This code is using 2nd Approach.
class Solution {
public:
	string optimalDivision(vector<int>& nums) {

		string ret = to_string(nums[0]);

		if (nums.size() == 1)
		{
			return ret;
		}

		if (nums.size() == 2)
		{
			return ret + "/" + to_string(nums[1]);
		}

		ret += "/(";

		for (int i = 1; i < nums.size(); i++)
		{
			if (i < nums.size() - 1)
			{
				ret += to_string(nums[i]) + "/";
			}
			else
			{
				ret += to_string(nums[i]) + ")";
			}
		}

		return ret;
	}
};

//this solution return just max value
//not expression
class Solution {

    struct dividStr
    {
        float f;
        string s;
    };

    dividStr divid(int start, int end, vector<int>& nums)
    {
        if (start == end)
        {
            return dividStr { static_cast<float>(nums[start]) , to_string(nums[start]) };
        }
        
        dividStr ret = { 0.f , "" };

        for (int i = start; i < end; i++)
        {
            dividStr left = divid(start, i, nums);
            dividStr right = divid(i + 1, end, nums);

            if (ret.f < left.f / right.f)
            {
                ret.f = left.f / right.f;

                if (i + 1 == end)
                {
                    ret.s = left.s + "/" + right.s;
                }
                else
                {
                    ret.s = left.s + "/" + "(" + right.s + ")";
                }
            }
        }

        return ret;
    }

public:
    string optimalDivision(vector<int>& nums) {

        auto ret = divid(0, nums.size() - 1, nums);

        return ret.s;
    }
};

public class Solution {

    public String optimalDivision(int[] nums) {

        Map<String, pair> memory = new HashMap<>();

        pair sol = divid(nums, 0, nums.length - 1, memory);

        return sol.maxS;
    }

    public pair divid(int[] nums, int start, int end, Map<String, pair> memory) {
        
        String key = start + " " + end;
        
        if (memory.containsKey(key)) 
            return memory.get(key);
        
        if (start == end)
            return new pair(nums[start], "" + nums[start], nums[start], "" + nums[start]);

        pair sol = new pair(0, "", 0, "");

        for (int i = start; i < end; i++)
        {
            pair left = divid(nums, start, i, memory);
            pair right = divid(nums, i + 1, end, memory);

            double min = left.min / right.max;
            String minS = left.minS + "/" + (i + 1 == end ? right.maxS : "(" + right.maxS + ")");

            double max = left.max / right.min;
            String maxS = left.maxS + "/" + (i + 1 == end ? right.minS : "(" + right.minS + ")");

            if (sol.min == 0 || min < sol.min)
            {
                sol.min = min;
                sol.minS = minS;
            }

            if (max > sol.max)
            {
                sol.max = max;
                sol.maxS = maxS;
            }
        }
        memory.put(key, sol);
        return sol;
    }
}

class pair {
    double min;
    String minS;
    double max;
    String maxS;

    public pair(double min, String minS, double max, String maxS) {
        this.min = min;
        this.minS = minS;
        this.max = max;
        this.maxS = maxS;
    }
}


//https://leetcode.com/problems/optimal-division/solutions/1306765/c-effective-approach-easy-maths-solution-proper-explanation-faster-than-100/?orderBy=most_votes

//solve this problem as this solution
//https://leetcode.com/problems/optimal-division/solutions/101684/brute-force-with-memory-in-case-of-your-interviewer-forbid-tricky-solution/?orderBy=most_votes
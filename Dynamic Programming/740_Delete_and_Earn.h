class Solution {

    int max = 0;

    void dfs(std::unordered_set<int>& visit, vector<int>& nums, int index, std::unordered_set<int>& us, int sum)
    {
        if (nums.size() <= index)
        {
            max = std::max(max, sum);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visit.count(i))
            {
                continue;
            }

            int sum2 = sum;

            if (0 == us.count(nums[i]))
            {
                sum2 += nums[i];
            }

            visit.insert(i);

            us.insert(nums[i] + 1);
            us.insert(nums[i] - 1);
            
            dfs(visit, nums, index + 1, us, sum2);

            us.erase(nums[i] + 1);
            us.erase(nums[i] - 1);

            visit.erase(i);
        }
    }

public:
    int deleteAndEarn(vector<int>& nums) {

        std::unordered_set<int> visit;
        std::unordered_set<int> us;

        dfs(visit, nums, 0, us, 0);

        return max;
    }
};

class Solution {
public:
	int solve(vector<int>& arr, int i)
	{
		if (i >= arr.size()) // if i is greater than size of array
		{
			return 0; // then simply returnn zero
		}

		// current 'i' on which we are standing
		int currValue = arr[i];  // current value
		int currSum = arr[i]; // intial make sum as same as value
		int index = i + 1; // index to take elemets, so  i + 1

		// while it is the same as the current value, include in our sum
		while (index < arr.size() && arr[index] == currValue)
		{
			currSum += arr[i];
			index++;
		}

		// Now, we have to skip all the elements, whose value is equal to
		// currValue + 1
		while (index < arr.size() && arr[index] == currValue + 1)
		{
			index++;
		}

		//And lastly, we have two choices-
		//whether to include the sum of this current element in our answer
		// or not include the sum of current element in our answer
		// so we explore all possibility and take maximum of them

		return max(currSum + solve(arr, index), solve(arr, i + 1));

		// If we decide to take the curr element in our answer, then upto the elemet we skip the next value, we paas that index
		// but if decided no to make this vurrent element then simply paas
		// i + 1
	}
	int deleteAndEarn(vector<int>& arr) {
		int n = arr.size(); // take the size of the array

		// sort the array to get rid of all arr[i] - 1 elements
		sort(arr.begin(), arr.end());

		// solve function which give us our final answer
		return solve(arr, 0);
		//                ??
		//                we start from zero index
	}
};
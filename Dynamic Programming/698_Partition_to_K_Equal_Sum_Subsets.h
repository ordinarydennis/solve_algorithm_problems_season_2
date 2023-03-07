class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		
		int sum = 0;
		
		for (int num : nums)
			sum += num;
		
		if (k <= 0 || sum % k != 0)
			return false;

		vector<int> visited(nums.size(), 0);

		return canPartition(nums, visited, 0, k, 0, 0, sum / k);
	}

	bool canPartition(vector<int>& nums, vector<int>& visited, int start_index, int k, int cur_sum, int cur_num, int target) {
		
		if (k == 1)
			return true;

		if (cur_sum == target && cur_num > 0)
			return canPartition(nums, visited, 0, k - 1, 0, 0, target);
		
		for (int i = start_index; i < nums.size(); i++) 
		{
			if (!visited[i])
			{
				visited[i] = 1;

				if (canPartition(nums, visited, i + 1, k, cur_sum + nums[i], cur_num++, target))
					return true;

				visited[i] = 0;
			}
		}
		return false;
	}
};
https://leetcode.com/problems/partition-to-k-equal-sum-subsets/solutions/108730/java-c-straightforward-dfs-solution/?orderBy=most_votes

class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = 0;
		sum = accumulate(nums.begin(), nums.end(), sum);
		if (nums.size() < k || sum % k) return false;

		vector<int>visited(nums.size(), false);
		return backtrack(nums, visited, sum / k, 0, 0, k);
	}

	bool backtrack(vector<int>& nums, vector<int>visited, int target, int curr_sum, int i, int k) {
		if (k == 1)
			return true;

		if (curr_sum == target)
			return backtrack(nums, visited, target, 0, 0, k - 1);

		for (int j = i; j < nums.size(); j++) {
			if (visited[j] || curr_sum + nums[j] > target) continue;

			visited[j] = true;
			if (backtrack(nums, visited, target, curr_sum + nums[j], j + 1, k)) return true;
			visited[j] = false;
		}

		return false;
	}
};
https://leetcode.com/problems/partition-to-k-equal-sum-subsets/solutions/1273738/c-simple-and-clean-backtracking-solution/?orderBy=most_votes

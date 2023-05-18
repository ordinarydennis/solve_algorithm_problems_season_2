class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {

		int start = 0;
		int end = numbers.size() - 1;

		while (start < end)
		{

			if (target < numbers[start] + numbers[end])
			{
				end--;
			}
			else if (numbers[start] + numbers[end] < target)
			{
				start++;
			}
			else
			{
				return vector<int>{ start + 1, end + 1 };
			}
		}

		return {};
	}
};

//using hash_map
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {

		std::unordered_map<int, int> m;

		for (int i = 0; i < numbers.size(); i++)
		{
			if (m.count(target - numbers[i]))
			{
				return vector<int>{ m[target - numbers[i]], i + 1};
			}

			m.emplace(numbers[i], i + 1);
		}

		return {};
	}
};


//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/solutions/2128516/4-approaches-brute-force-hashmap-binary-search-two-pointers/
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

		std::unordered_map<int, int> memo;
		std::stack<int> st;

		std::vector<int> ret(nums1.size(), -1);

		for (int i = 0; i < nums2.size(); i++)
		{
			while(st.size() && st.top() < nums2[i])
			{
				memo[st.top()] = nums2[i];
				st.pop();
			}

			st.push(nums2[i]);
		}
	
		for (int i = 0; i < nums1.size(); i++)
		{
			auto it = memo.find(nums1[i]);

			if (memo.end() != it)
			{
				ret[i] = it->second;
			}
		}

		return ret;
	}
};

//need to read solution
//https://leetcode.com/problems/next-greater-element-i/solutions/671261/c-map-stack-commented/?orderBy=most_votes&languageTags=cpp

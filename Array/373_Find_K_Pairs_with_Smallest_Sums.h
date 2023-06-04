class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

		std::priority_queue<std::pair<int, std::pair<int, int>>> pq;

		for (int i = 0; i < nums1.size(); i++)
		{
			for (int j = 0; j < nums2.size(); j++)
			{
				int sum = nums1[i] + nums2[j];

				if (pq.size() < k)
				{
					pq.push(pair{ sum, pair{nums1[i] , nums2[j]} });
				}
				else if(sum < pq.top().first)
				{
					pq.pop();
					pq.push(pair{ sum, pair{nums1[i] , nums2[j]} });
				}
				else
				{
					break;
				}
			}
		}

		vector<vector<int>> ret;

		while (pq.size())
		{
			auto t = pq.top();

			const auto& e = t.second;
			ret.push_back(std::vector<int> { e.first, e.second });
			pq.pop();
		}

		return ret;
	}
};


//read solution
//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/solutions/596658/c-solution-with-diagram-explaination-for-beginners/
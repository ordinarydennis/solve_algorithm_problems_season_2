class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& num) {

		vector<vector<int> > res;

		std::sort(num.begin(), num.end());

		for (int i = 0; i < num.size(); i++) {

			int target = -num[i];
			int front = i + 1;
			int back = num.size() - 1;

			while (front < back) {

				int sum = num[front] + num[back];

				// Finding answer which start from number num[i]
				if (sum < target)
					front++;

				else if (sum > target)
					back--;

				else {
					vector<int> triplet = { num[i], num[front], num[back] };
					res.push_back(triplet);

					// Processing duplicates of Number 2
					// Rolling the front pointer to the next different number forwards
					while (front < back && num[front] == triplet[1]) front++;

					// Processing duplicates of Number 3
					// Rolling the back pointer to the next different number backwards
					while (front < back && num[back] == triplet[2]) back--;
				}

			}

			// Processing duplicates of Number 1
			// to avoid same answer.
			while (i + 1 < num.size() && num[i + 1] == num[i])
				i++;

		}

		return res;

	}
};

//https://leetcode.com/problems/3sum/solutions/7402/share-my-ac-c-solution-around-50ms-o-n-n-with-explanation-and-comments/
class Solution {

	int makeTree(vector<int>& arr, int target)
	{
		int ret = 0;

		for (int a = 0; a < arr.size(); a++)
		{
			for (int b = 0; b < arr.size(); b++)
			{
				if (target == a * b)
				{
					ret++;
				}
			}

			makeTree(arr, a);
		}

		return ret;
	}

public:
	int numFactoredBinaryTrees(vector<int>& arr) {




	}
};

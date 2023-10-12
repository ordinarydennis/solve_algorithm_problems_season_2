class Solution {

	std::unordered_map<int, int> memo;

	void findFibo(vector<int>& arr, int n1, int n2, int index, int& count)
	{
		int size = static_cast<int>(arr.size());

		for (int i = index; i < size; i++)
		{
			if (n1 + n2 != arr[i])
				continue;

			count++;

			findFibo(arr, n2, arr[i], i + 1, count);

			break;
		}
	}

public:
	int lenLongestFibSubseq(vector<int>& arr) {

		int ret = 0;

		int size = static_cast<int>(arr.size());

		for (int i = 0; i < size - 1; i++)
		{
			for (int a = i + 1; a < size; a++)
			{
				int c = 2;

				findFibo(arr, arr[i], arr[a], a + 1, c);

				if (2 < c)
				{
					ret = std::max(ret, c);
				}
			}
		}
		
		return ret;
	}
};

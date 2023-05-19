class Solution {
public:
	int countPrimes(int n) {

		if (n <= 2)
			return 0;

		if (n <= 3)
			return 1;

		std::vector<int> primes = { 2, 3 };

		for (int i = 5; i < n; i++)
		{
			int j = 0;

			for (; j < primes.size(); j++)
			{
				if (i % primes[j] == 0)
				{
					break;
				}
			}

			if (primes.size() == j)
			{
				primes.push_back(i);
			}
		}

		return primes.size();
	}
};
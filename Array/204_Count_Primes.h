class Solution {
public:
	int countPrimes(int n) {

		if (0 == n || 1 == n)
		{
			return 0;
		}

		std::vector<int> sieve(n, 1);

		int count = 0;

		for (int i = 2; i < n; i++)
		{
			if (0 == sieve[i])
				continue;

			count++;

			for (int j = 2; i * j < n; j++)
			{
				sieve[i * j] = 0;
			}
		}

		return count;
	}
};

//https://leetcode.com/problems/count-primes/solutions/1200796/js-python-java-c-easy-sieve-of-eratosthenes-solution-w-explanation/
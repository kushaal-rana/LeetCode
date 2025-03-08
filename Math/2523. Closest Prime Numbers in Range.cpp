/*
Problem Link: https://leetcode.com/problems/closest-prime-numbers-in-range/
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution
{
public:
    bool isPrime(int num)
    {
        if (num == 1)
            return false;
        if (num == 2)
            return true;
        if (num % 2 == 0)
            return false;
        for (int i = 3; i * i <= num; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> primes;
        for (int num = left; num <= right; num++)
        {
            if (isPrime(num))
                primes.push_back(num);
        }
        if (primes.size() < 2)
            return {-1, -1};
        int mini = INT_MAX;
        int first = -1, second = -1;
        for (int i = 0; i < primes.size() - 1; i++)
        {
            if ((primes[i + 1] - primes[i]) < mini)
            {
                first = primes[i];
                second = primes[i + 1];
                mini = (primes[i + 1] - primes[i]);
            }
        }

        return {first, second};
    }
};

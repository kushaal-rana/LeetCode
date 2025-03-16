/*
Problem Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
Time Complexity: O(n*n)
Brute Force
*/
class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        int maxCandy = INT_MIN;
        int n = candies.size(), total = 0;

        maxCandy = *max_element(candies.begin(), candies.end());
        for (int candy : candies)
        {
            total += candy;
        }
        // If total candies are less than k, return 0
        if (total < k)
            return 0;

        // Brute Force: try from maxC till 1 candy
        for (int c = maxCandy; c >= 1; c--)
        {
            long long count = 0;
            for (int i = 0; i < candies.size(); i++)
            {
                count += candies[i] / c; // how many children can get c candies from this pile
            }
            if (count >= k)
                return c;
        }
        return 0;
    }
};
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
// Approach: Using Binary Search
class Solution
{
public:
    bool canDistribute(vector<int> &candies, int mid, long long k)
    {
        int n = candies.size();
        long long count = 0;
        for (int i = 0; i < n; i++)
        {
            // count += candies[i]/mid; insted of this we can also do
            k -= candies[i] / mid;
            if (k <= 0)
                return true; // Early Return
        }
        return k <= 0; // All children got mid candies
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        int maxCandy = INT_MIN;
        int n = candies.size();
        long long total = 0, result = 0;

        maxCandy = *max_element(candies.begin(), candies.end());
        for (int candy : candies)
        {
            total += candy;
        }
        // If total candies are less than k, return 0
        if (total < k)
            return 0;

        int l = 1;
        int r = maxCandy;
        while (l <= r)
        { // N * log(maxC)
            int mid = l + (r - l) / 2;
            if (canDistribute(candies, mid, k))
            {
                result = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return result;
    }
};
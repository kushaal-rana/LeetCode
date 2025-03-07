/*
Problem Link: https://leetcode.com/problems/find-missing-and-repeated-values/
Time Complexity: O(n^2)
Space Complexity: O(n)
Approach 1: Using Map
*/
class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        map<int, int> mp;
        int n = grid.size();
        int repeating = 0, missing = 0;
        for (auto vec : grid)
        {
            for (int it : vec)
            {
                mp[it]++;
            }
        }
        for (int i = 1; i <= grid.size() * grid.size(); i++)
        {
            if (mp.count(i))
            {
                if (mp[i] > 1)
                {
                    repeating = i;
                }
            }
            else
            {
                missing = i;
            }
        }
        if (missing == 0)
            missing = n;
        return {repeating, missing};
    }
};

/*
Approach 2: Using Math
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        long long N = n * n;
        long long gridSum = 0;
        long long gridSqSum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                gridSum += grid[i][j];
                gridSqSum += grid[i][j] * grid[i][j];
            }
        }
        long long sum = (N * (N + 1)) / 2;
        long long sqSum = (N * (N + 1) * (2 * N + 1)) / 6;

        int sqDiff = gridSqSum - sqSum;
        int sumDiff = gridSum - sum;

        int a = (sqDiff / sumDiff + sumDiff) / 2;
        int b = (sqDiff / sumDiff - sumDiff) / 2;

        return {a, b};
    }
};
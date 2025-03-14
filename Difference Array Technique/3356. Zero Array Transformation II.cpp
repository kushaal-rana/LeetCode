// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
// TC: O(Q*(Q+N))
// SC: O(N+N)
// Approach 1: Difference Array Technique + Linear Query Check
class Solution
{
public:
    bool checkWithDifferenceArrayTechnique(vector<int> &nums, vector<vector<int>> &queries, int k)
    {
        int n = nums.size();
        vector<int> diff(nums.size(), 0);
        // O(K)
        for (int i = 0; i <= k; i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            int val = queries[i][2];

            diff[start] += val;
            if (end + 1 < n)
            {
                diff[end + 1] -= val;
            }
        }
        int cumSum = 0;
        for (int i = 0; i < n; i++)
        { // O(N)
            cumSum += diff[i];
            diff[i] = cumSum;
            if (nums[i] > diff[i])
                return false;
        }
        return true;
    }

    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int q = queries.size();
        auto lambda = [](int x)
        {
            return x == 0;
        };
        // if(checkAllZeroAlready()) return 0;//no operations required as all are 0 initially.
        if (all_of(begin(nums), end(nums), lambda))
            return 0; // no operations required as all are 0 initially.
        for (int i = 0; i < q; i++)
        { // O (Q * (Q+n))
            if (checkWithDifferenceArrayTechnique(nums, queries, i) == true)
            {
                return i + 1;
            }
        }
        return -1;
    }
};

// Approach 2: Difference Array Technique + Binary Search
bool checkWithDifferenceArrayTechnique(vector<int> &nums, vector<vector<int>> &queries, int k)
{
    int n = nums.size();
    vector<int> diff(nums.size(), 0);
    // O(K)
    for (int i = 0; i <= k; i++)
    {
        int start = queries[i][0];
        int end = queries[i][1];
        int val = queries[i][2];

        diff[start] += val;
        if (end + 1 < n)
        {
            diff[end + 1] -= val;
        }
    }
    int cumSum = 0;
    for (int i = 0; i < n; i++)
    { // O(N)
        cumSum += diff[i];
        diff[i] = cumSum;
        if (nums[i] > diff[i])
            return false;
    }
    return true;
}

int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    int q = queries.size();
    auto lambda = [](int x)
    {
        return x == 0;
    };
    // if(checkAllZeroAlready()) return 0;//no operations required as all are 0 initially.
    if (all_of(begin(nums), end(nums), lambda))
        return 0; // no operations required as all are 0 initially.

    int l = 0, r = q - 1, result = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (checkWithDifferenceArrayTechnique(nums, queries, mid) == true)
        {
            result = mid + 1; // for returning count not index
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return result;
}
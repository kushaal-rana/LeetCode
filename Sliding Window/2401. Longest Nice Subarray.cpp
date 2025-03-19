/*
    Problem Link - https://leetcode.com/problems/longest-nice-subarray/
    Time Complexity - O(n)
    Space Complexity - O(1)
    Apporach 1 - Sliding Window
*/

int longestNiceSubarray(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0;
    int result = 1;
    int mask = 0;
    while (j < n)
    {
        while ((mask & nums[j]) != 0)
        { // keep shrinking
            mask = (mask ^ nums[i]);
            i++;
        }
        result = max(result, j - i + 1);
        mask = (mask | nums[j]);
        j++;
    }
    return result;
}

/*
Approach 2 - O(N^2)
*/
int longestNiceSubarray(vector<int> &nums)
{
    int n = nums.size();
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        for (int j = i; j < n; j++)
        {
            if ((mask & nums[j]) == 0)
            {
                mask = (mask | nums[j]);
                result = max(result, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return result;
}
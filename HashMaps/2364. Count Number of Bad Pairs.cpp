class Solution
{
public:
    /* Approach whenever an equation is given j - i != nums[j] - nums[i]
        try bringing like/similar terms together
        nums[j]-j = nums[i]-i;
    */
    //    TC: O(n)
    //    SC: O(n)
    long long approach2(vector<int> &nums)
    {
        int n = nums.size();
        long long result = 0;
        unordered_map<int, int> mp;
        for (int j = 0; j < n; j++)
        {
            int diff = nums[j] - j;
            int goodPairs = mp[diff];
            int totalPairsInPast = j;
            result += totalPairsInPast - goodPairs;
            mp[diff]++;
        }
        return result;
    }
    long long approach1(vector<int> &nums)
    {
        int n = nums.size();
        long long result = 0;
        unordered_map<int, int> mp;
        mp[nums[0]] = 1;
        for (int j = 1; j < n; j++)
        {
            int countOfNumsJ = mp[j - nums[j]];
            int totalNumsBeforeJ = j;
            int badPairs = totalNumsBeforeJ - countOfNumsJ;
            result += badPairs;

            mp[j - nums[j]]++;
        }
        return result;
    }
    long long countBadPairs(vector<int> &nums)
    {
        // return approach1(nums);
        return approach2(nums);
    }
};
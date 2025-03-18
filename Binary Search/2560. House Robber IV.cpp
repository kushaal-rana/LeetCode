// Approach - 1 Recursion
//  Time Complexity: O(k*n)
class Solution
{
public:
    int rob(vector<int> &nums, int k, int n, vector<vector<int>> &dp)
    {
        if (k == 0)
            return 0; // no more house to be covered.

        if (n < 0)
            return INT_MAX; // invalid path

        if (dp[k][n] != -1)
            return dp[k][n];
        int robed = max(nums[n], rob(nums, k - 1, n - 2, dp));
        int didntRob = rob(nums, k, n - 1, dp);
        return dp[k][n] = min(robed, didntRob);
    }
    int minCapability(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return rob(nums, k, n - 1, dp);
    }
};

// Approach - 2 Binary Search
// Time Complexity: O(log(maxCapability(->mid))*n)

class Solution
{
public:
    // int rob(vector<int>& nums, int k, int n, vector<vector<int>>& dp){
    //     if(k==0) return 0; //no more house to be covered.

    //     if(n<0) return INT_MAX; //invalid path

    //     if(dp[k][n] !=-1) return dp[k][n];
    //     int robed =  max(nums[n],rob(nums,k-1,n-2,dp));
    //     int didntRob = rob(nums,k,n-1,dp);
    //     return dp[k][n] = min(robed,didntRob);
    // }
    bool isPossible(vector<int> &nums, int mid, int k)
    {
        int houses = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= mid)
            {
                houses++;
                i++; // skipping adj house
            }
        }
        return houses >= k; // we managed to rob atleast k houses
    }
    int minCapability(vector<int> &nums, int k)
    { // O(log(maxCapability(->mid))*n)
        int n = nums.size();
        // vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        // return rob(nums,k,n-1,dp);
        int l = *min_element(begin(nums), end(nums));
        int r = *max_element(begin(nums), end(nums));
        int result = r;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isPossible(nums, mid, k) == true)
            {
                r = mid - 1;
                result = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
};
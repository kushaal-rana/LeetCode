// Greedy Solution in Greedy Folder
class Solution
{
public:
    // TC: O(n^k): k,k,k, we have k possiblities in every state or number and we have to choose for n number
    bool solve(int idx, int n, vector<int> &nums, vector<int> &dp)
    {
        if (idx >= n - 1)
            return true;
        if (dp[idx] != -1)
            return dp[idx];
        for (int i = 1; i <= nums[idx]; i++)
        {
            if (solve(i + idx, n, nums, dp))
            {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    // O(N^2)
    bool bottomUp(vector<int> &nums)
    {
        int n = nums.size();
        // dp[i] = if i am able to reach the ith index or not
        vector<int> dp(10001, 0);
        dp[0] = 1; // initially you are starting from 0 so you can reach 0
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (dp[j] == true && j + nums[j] >= i)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        for (auto it : dp)
        {
            cout << it << ' ';
        }
        return dp[n - 1];
    }
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return bottomUp(nums);
        // return solve(0,n,nums,dp);
    }
};
class Solution
{
public:
    void recursion(int idx, vector<int> &nums, vector<int> &result, vector<int> &temp, int prev)
    {
        if (idx >= nums.size())
        {
            if (temp.size() > result.size())
            {
                result = temp;
            }
            return;
        }
        // Take Option
        if (prev == -1 || nums[idx] % prev == 0)
        {
            temp.push_back(nums[idx]); // take
            recursion(idx + 1, nums, result, temp, nums[idx]);
            temp.pop_back(); // not_take
        }
        recursion(idx + 1, nums, result, temp, prev);
    }

    vector<int> bottomUp(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev_idx(n, -1);
        int maxL = 1;
        int last_chosen_index = 0; // This is to track from where do i start printing answer
        // where did I get the Max Length
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = 1 + dp[j];
                        prev_idx[i] = j;
                    }
                    if (dp[i] > maxL)
                    {
                        maxL = dp[i];
                        last_chosen_index = i;
                    }
                }
            }
        }
        vector<int> result;
        while (last_chosen_index != -1)
        {
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }
        return result;
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        vector<int> result;
        vector<int> temp;
        int prev = -1;
        return bottomUp(nums);
        recursion(0, nums, result, temp, prev);
        return result;
    }
};
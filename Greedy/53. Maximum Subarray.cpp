class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int startIdx = 0, startEnd = 0, start = 0;
        int sum = 0, maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (maxi < sum)
            {
                maxi = sum;
                startIdx = start;
                startEnd = i;
            }
            if (sum < 0)
            {
                sum = 0;
                start = i + 1;
            }
        }
        for (int i = startIdx; i <= startEnd; i++)
        {
            cout << nums[i] << " ";
        }
        return maxi;
    }
};
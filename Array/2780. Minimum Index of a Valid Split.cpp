// https://leetcode.com/problems/minimum-index-of-a-valid-split/
// Approach 1: Brute Force

class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        int n = nums.size();

        for (int &num : nums)
        {
            mp2[num]++;
        }
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];

            mp1[num]++;
            mp2[num]--;
            int n1 = i + 1;
            int n2 = n - i - 1;
            if (mp1[num] * 2 > n1 && mp2[num] * 2 > n2)
            { // division operation is a bit costly so
                return i;
            }
        }
        return -1;
    }
};
// Approach 2: Boyre-Moore Algorithm
class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int n = nums.size();
        int maj = -1;
        int count = 0;
        // Boyre-Moore Algorithm
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                maj = nums[i];
                count = 1;
            }
            else if (nums[i] == maj)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        int majCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maj)
            {
                majCount++;
            }
        }
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maj)
            {
                count++; // right subArray count ke liye
            }
            int n1 = i + 1;
            int n2 = n - i - 1;
            int remainingCount = majCount - count;
            if (count * 2 > n1 && remainingCount * 2 > n2)
            {
                return i;
            }
        }
        return -1;
    }
};
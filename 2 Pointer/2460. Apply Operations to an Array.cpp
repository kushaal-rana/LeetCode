//  2 Pointer Approach : 2 Pass Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1] && nums[i] != 0)
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int i = 0, j = 0;
        while (j < n)
        {
            if (nums[j] != 0)
            {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        while (i < n)
        {
            nums[i] = 0;
            i++;
        }
        return nums;
    }
};
// 2 Pointer Approach : 1 Pass Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> applyOperations(vector<int> &nums)
{
    int n = nums.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && nums[i] == nums[i + 1] && nums[i] != 0)
        {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
        if (nums[i] != 0)
        {
            if (i != j)
            {
                swap(nums[i], nums[j]);
            }
            j++;
        }
    }
    return nums;
}
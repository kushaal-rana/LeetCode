// https://leetcode.com/problems/number-of-alternating-subarrays
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors)
    {
        int n = colors.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (colors[(i - 1 + n) % n] != colors[i] && colors[i] != colors[(i + 1) % n])
            {
                ans++;
            }
        }
        return ans;
    }
};
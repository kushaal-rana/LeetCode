// Problem Link: https://leetcode.com/problems/alternating-groups/
// Time Complexity: O(n+k-1)
// Space Complexity: O(1)
class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size(), ans = 0;
        for (int i = 0; i < k - 1; i++)
        {
            colors.push_back(colors[i]); // to handle wrap around(circular array)
            colors.push_back(colors[i]);
        }
        int i = 0, j = i + 1;
        while (j < n + k - 1)
        {
            if (colors[j] == colors[j - 1])
            {
                i = j;
            }
            if (j - i + 1 == k)
            {
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
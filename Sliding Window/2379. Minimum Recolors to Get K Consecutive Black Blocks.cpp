/*
    Problem Link - https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
    Time Complexity - O(n)
    Space Complexity - O(1)
*/
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int i = 0;
        int j = 0;
        int count = 0, mini = INT_MAX;
        int n = blocks.size();
        while (j < n)
        {
            if (blocks[j] == 'W')
            {
                count++;
            }
            if (j - i + 1 == k)
            {
                mini = min(count, mini);
                if (blocks[i] == 'W')
                {
                    count--;
                }
                i++;
            }
            j++;
        }
        return mini;
    }
};
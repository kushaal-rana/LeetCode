/*
Problem Link: https://leetcode.com/problems/count-total-number-of-colored-cells
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution
{
public:
    long long coloredCells(int n)
    {
        int time = 1;
        long long cells = 1;
        while (time <= n)
        {
            cells += 4 * (time - 1);
            time++;
        }
        return cells;
    }
};
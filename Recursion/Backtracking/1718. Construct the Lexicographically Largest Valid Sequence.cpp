
class Solution
{
public:
    /*Approach 1. (Using simple backtracking Khandani Template)
    Approach: Size should be 2*n-1
    2. Used->set, to keep track of used ele
    3. Apart from 1 others all will be placed at i=j=i+nums[i];
    4. For any index, i will try to put largest No,, if no possile then 2nd largest.. so on.(=>lex largest)
    T.C : O(n!)
    S.C : O(n)
    */
    bool solve(int i, int n, vector<int> &result, vector<int> &used)
    {
        if (i >= result.size())
        {
            return true; // guranteed answer: we filled larger num first
        }
        if (result[i] != -1)
        {
            return solve(i + 1, n, result, used);
        }
        for (int num = n; num >= 1; num--)
        {
            if (used[num])
                continue;
            // try
            used[num] = true;
            result[i] = num;
            // explore
            if (num == 1)
            {
                if (solve(i + 1, n, result, used) == true)
                    return true;
            }
            else
            {
                int j = num + i;
                if (j < result.size() && result[j] == -1)
                {
                    result[j] = num;
                    if (solve(i + 1, n, result, used) == true)
                        return true;
                    result[j] = -1;
                }
            }
            // Undo
            used[num] = false;
            result[i] = -1;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n)
    {
        int size = 2 * n - 1;
        vector<int> used(n + 1, false);
        vector<int> result(size, -1);
        solve(0, n, result, used);
        return result;
    }
};
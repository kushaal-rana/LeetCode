// Approach-1 (Khandani Backtracking Template - storing all possible strings)
// T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
// S.C : O(n * 2^n) , total 2^n strings eaching having length n
class Solution
{
public:
    void solve(int i, int n, string curr, vector<string> &result)
    {
        if (curr.length() == n)
        {
            result.push_back(curr);
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++)
        {
            if (!curr.empty() && curr.back() == ch)
                continue;
            curr.push_back(ch);            // DO
            solve(i + 1, n, curr, result); // EXPLORE
            curr.pop_back();               // UNDO
        }
    }
    string getHappyString(int n, int k)
    {
        vector<string> result;
        solve(0, n, "", result);
        return (k > result.size()) ? "" : result[k - 1];
    }
};
// Approach-2 (Khandani Backtracking Template - Without storing all possible strings)
// T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
// S.C : O(n) by recursion system stack
class Solution
{
public:
    void solve(int n, int &count, string curr, int k, string &result)
    {
        if (curr.length() == n)
        {
            count++;
            if (count == k)
            {
                result = curr;
            }
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++)
        {
            if (!curr.empty() && curr.back() == ch)
                continue;
            curr.push_back(ch);               // DO
            solve(n, count, curr, k, result); // EXPLORE
            curr.pop_back();                  // UNDO
        }
    }
    string getHappyString(int n, int k)
    {
        string result = "";
        int count = 0;
        solve(n, count, "", k, result);
        return result;
    }
};
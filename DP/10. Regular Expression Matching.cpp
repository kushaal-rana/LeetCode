class Solution
{
    // TC:  2^n because in * we are calling 2 times recursion.
    // SC: max depth of tree ->max(length of s, or p)
    // taking substring is increasing time complexity O(n) so we can take i and j pointers too
public:
    bool solve(string s, string p)
    {
        if (p.size() == 0)
        {
            return s.length() == 0;
        }
        bool first_char_matched = false;
        if (s.length() > 0 && (s[0] == p[0] || p[0] == '.'))
        {
            first_char_matched = true;
        }
        if (p[1] == '*')
        {
            bool notTake = solve(s, p.substr(2));
            bool take = first_char_matched && solve(s.substr(1), p);
            return notTake || take;
        }
        else
        {
            return first_char_matched && solve(s.substr(1), p.substr(1));
        }
        return true;
    }
    bool isMatch(string s, string p)
    {
        return solve(s, p);
    }
};
class Solution
{
    // TC:  n*m because in * we are calling 2 times recursion.
    // SC: max depth of tree ->max(length of s, or p)
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (j == p.size())
        {
            return i == s.length();
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        bool first_char_matched = false;
        if (i < s.length() && (s[i] == p[j] || p[j] == '.'))
        {
            first_char_matched = true;
        }
        if (j + 1 < p.length() && p[j + 1] == '*')
        {
            bool notTake = solve(i, j + 2, s, p, dp);
            bool take = first_char_matched && solve(i + 1, j, s, p, dp);
            return dp[i][j] = notTake || take;
        }

        return dp[i][j] = first_char_matched && solve(i + 1, j + 1, s, p, dp);
    }
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(21, vector<int>(21, -1));
        return solve(0, 0, s, p, dp);
    }
};
class Solution
{
public:
    // APPROACH 2 TC: O(N)
    string clearDigits(string s)
    {
        int n = s.size();
        stack<int> st;
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
}
// APPROACH 1
string
clearDigits(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            if (i > 0)
            {
                s.erase(i - 1, 1);
                n--;
                i--;
            }
            s.erase(i, 1);
            n--;
            i--;
        }
    }
    return s;
}
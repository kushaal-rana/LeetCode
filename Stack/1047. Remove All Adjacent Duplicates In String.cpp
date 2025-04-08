class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        string result = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() || st.top() != s[i])
            {
                st.push(s[i]);
            }
            else if (st.top() == s[i])
            {
                st.pop();
            }
        }
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(begin(result), end(result));
        return result;
    }
};
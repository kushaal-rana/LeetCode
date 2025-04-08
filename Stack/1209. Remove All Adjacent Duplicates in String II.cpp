class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        if (k == 1)
            return "";
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty())
            {
                st.push({s[i], 1});
            }
            else if (st.top().first == s[i])
            {
                auto p = st.top();
                st.pop();
                p.second++;
                if (p.second == k)
                {
                    continue;
                }
                else
                {
                    st.push(p);
                }
            }
            else
            {
                st.push({s[i], 1});
            }
        }
        string result = "";
        while (!st.empty())
        {
            int count = st.top().second;
            while (count--)
                result += st.top().first;
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
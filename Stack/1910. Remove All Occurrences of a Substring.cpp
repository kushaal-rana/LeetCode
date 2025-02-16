
// Approach - 1 O(N^2)
class Solution
{
public:
    // TC: O(N^2)
    string removeOccurrences(string s, string part)
    {
        while (true)
        {                           // O(M)*O(N)
            int idx = s.find(part); // O(N);
            if (idx == string::npos)
            {
                break;
            }
            s.erase(idx, part.size()); //(O(N));
        }
        return s;
    }
};

// Approach - 2 Stack
class Solution
{
public:
    // TC: O(N^2)
    // SC: O(N)
    bool check(string part, stack<char> st, int n)
    {
        stack<char> tempSt = st;
        for (int i = n - 1; i >= 0; i--)
        {
            if (tempSt.top() != part[i])
                return false;
            tempSt.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part)
    {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        { // O(N)
            st.push(s[i]);
            if (st.size() >= part.size() && check(part, st, part.size()) == true)
            { // O(M)
                for (int j = 0; j < part.size(); j++)
                {
                    st.pop();
                }
            }
        }
        string result = "";
        while (!st.empty())
        { // O(M)
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end()); // O(N)
        return result;
    }
};

// Approach - 3 O(N) String as Stack
class Solution
{
public:
    // TC: O(N)
    string removeOccurrences(string s, string part)
    {
        string result = "";
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            result.push_back(s[i]);
            if (result.size() >= part.size())
            {
                if (result.substr(result.size() - part.size()) == part)
                {
                    result.erase(result.size() - part.size());
                }
            }
        }
        return result;
    }
};

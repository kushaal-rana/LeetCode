// Approach-1 - (Simple brute force)
// T.C : O(n * (n+1)!), (n+1)! permuations and n for matchesPattern()
// S.C : O(n+1) for result
class Solution
{
public:
    bool matchesPatterns(string &num, string &pattern)
    {
        for (int i = 0; i < pattern.size(); i++)
        {
            if (pattern[i] == 'I' && num[i] > num[i + 1] || pattern[i] == 'D' && num[i] < num[i + 1])
            {
                return false;
            }
        }
        return true;
    }
    string smallestNumber(string pattern)
    {
        int n = pattern.size(); // IID, n = 3
        string num = "";
        for (int i = 1; i <= n + 1; i++)
        {
            num.push_back(i + '0'); // 1->'1'
        }
        while (!matchesPatterns(num, pattern))
        {
            next_permutation(begin(num), end(num));
        }
        return num;
    }
};

// Approach-2 - (Simple using string as a stack) - You can use a stack<int> as well
// T.C : O(n)
// S.C : O(n) for the result
class Solution
{
public:
    string smallestNumber(string pattern)
    {
        stack<char> st;
        int n = pattern.size();
        string num = "";
        int count = 1;
        for (int i = 0; i <= n; i++)
        {
            st.push(count + '0');
            if (i == n || pattern[i] == 'I')
            {
                while (!st.empty())
                {
                    num += st.top();
                    st.pop();
                }
            }
            count++;
        }
        return num;
    }
};
// String as Stack
class Solution
{
public:
    string smallestNumber(string pattern)
    {
        string st;
        int n = pattern.size();
        string num = "";
        int count = 1;
        for (int i = 0; i <= n; i++)
        {
            st.push_back(count + '0');
            count++;
            if (i == n || pattern[i] == 'I')
            {
                while (!st.empty())
                {
                    num += st.back();
                    st.pop_back();
                }
            }
        }
        return num;
    }
};
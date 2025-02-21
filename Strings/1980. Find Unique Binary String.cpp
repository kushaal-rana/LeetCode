// Approach-1 (Using simple conversion)
// T.C : O(n^2) - Iterating on each string and converting each character to integer
// S.C : O(n) - Using set
class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        string result = "";
        set<int> st;
        for (string &num : nums)
        {
            st.insert(stoi(num, 0, 2)); // converting sting to int and while converting(convert into decimal that is why 2)
        }
        for (int num = 0; num <= 65536; num++)
        {
            if (st.find(number) == st.end())
            {
                {
                    result = bitset<16>(num).to_string();
                    return result.substr(16 - n);
                }
            }
            return "";
        }
    }
};

// Approach-2 (Improving above code)
// We no need to check from 0 to 65536. Only need to check from 0 to n
// T.C : O(n^2) - Iterating on each string and converting each character to integer
// S.C : O(n) - Using set
class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_set<int> st;

        for (string &num : nums)
        {
            st.insert(stoi(num, 0, 2));
        }

        int n = nums.size();

        string result = "";

        for (int number = 0; number <= n; number++)
        {
            if (st.find(number) == st.end())
            {
                result = bitset<16>(number).to_string();
                break;
            }
        }

        return result.substr(16 - n);
    }
};

// Approach-3 Backtracking
// T.C : O(n * 2^n)
// S.C : O(1)
class Solution
{
public:
    bool solve(unordered_set<string> &st, string &result, int n)
    {
        if (result.size() == n)
        {
            if (st.find(result) == st.end())
                return true;
            return false;
        }
        for (int i = 0; i <= 1; i++)
        {
            result.push_back(i + '0');
            if (solve(st, result, n))
                return true;
            result.pop_back();
        }
        return false;
    }
    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_set<string> st;
        for (auto &it : nums)
            st.insert(it);
        string result = "";
        solve(st, result, nums.size());
        return result;
    }
};

// Approach-4 (By discarding matching characters in each position)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        string result = "";
        for (int i = 0; i < n; i++)
        {
            char ch = nums[i][i];
            if (ch == '0')
                result.push_back('1');
            else
                result.push_back('0');
        }
        return result;
    }
};
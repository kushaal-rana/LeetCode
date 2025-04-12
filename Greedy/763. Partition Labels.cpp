// https://leetcode.com/problems/partition-labels/
// Time Complexity: O(n)
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<int, int> mp;
        int n = s.size();
        int j = 0, end = 0;
        // last occurance of each characters
        for (int i = 0; i < n; i++)
        {
            mp[s[i] - 'a'] = i;
        }
        vector<int> result;
        int i = 0;
        while (i < n)
        {
            int end = mp[s[i] - 'a']; // curr char last index

            int j = i;
            while (j < end)
            {
                end = max(end, mp[s[j] - 'a']);
                j++;
            }
            result.push_back(j - i + 1);
            i = j + 1;
        }
        return result;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)
// Cleaner Code with no extra variable
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.size();
        vector<int> mp(26, -1);
        // last occurance of each characters
        for (int i = 0; i < n; i++)
        {
            mp[s[i] - 'a'] = i;
        }
        vector<int> result;
        int i = 0;
        int start = 0;
        int end = 0;
        while (i < n)
        {
            end = max(end, mp[s[i] - 'a']); // curr char last index

            if (i == end)
            {
                result.push_back(end - start + 1);
                start = end + 1;
            }
            i++;
        }
        return result;
    }
};
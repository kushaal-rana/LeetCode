// T.C : O(m+n) where m = length of s and n = length of t
// S.C : O(n)
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        if (t.length() > n)
            return "";
        unordered_map<char, int> mp;
        // Initially we insert the count of t in map
        for (char &ch : t)
        {
            mp[ch]++;
        }
        int requiredCount = t.length();
        int minWindowSize = INT_MAX;
        int start_i = 0, j = 0, i = 0;
        while (j < n)
        {
            if (mp[s[j]] > 0)
            {                    // Now we check if we found the same char
                requiredCount--; // decrease the count require
            }
            mp[s[j]]--; // decrease the count from map too
            while (requiredCount == 0)
            { // it means we found a substring which has all t char
                // Start Shrinking the Window
                int currWindowSize = j - i + 1;

                if (minWindowSize > currWindowSize)
                {
                    minWindowSize = currWindowSize;
                    start_i = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                {
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};
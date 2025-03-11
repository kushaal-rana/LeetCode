/*
    Problem Link - https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants/
    Approach 1: Brute Force
    Time Complexity - O(n^2)
    Space Complexity - O(N)
*/
class Solution
{
public:
    long long countOfSubstrings(string word, int k)
    {
        int n = word.size(), ans = 0;
        set<char> st;
        int vowel = 0;
        int consonent = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u')
                {
                    st.insert(word[j]); // 5
                }
                else
                {
                    consonent++; // 1
                }
                if (st.size() == 5 && consonent == k)
                {
                    ans++;
                    st.clear();
                    consonent = 0;
                    // i=j;
                }
            }
        }
        return ans;
    }
};

/*
    Approach 2: Sliding Window
    Time Complexity - O(n)
    Space Complexity - O(1)
*/
class Solution
{
public:
    bool isVovel(char &ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countOfSubstrings(string word, int k)
    {
        int n = word.size();

        unordered_map<char, int> mp;
        // Preprocessing: precompute the next consonent index
        vector<int> nextConsonent(n, 0);
        int newConsoIdx = n;
        for (int i = n - 1; i >= 0; i--)
        {
            nextConsonent[i] = newConsoIdx;
            if (!isVovel(word[i]))
            {
                newConsoIdx = i;
            }
        }
        // Sliding Window
        int i = 0, j = 0;
        long long count = 0;
        int consonent = 0;
        while (j < n)
        {
            char ch = word[j];
            if (isVovel(ch))
            {
                mp[ch]++;
            }
            else
            {
                consonent++;
            }
            while (consonent > k)
            { // shrink
                if (isVovel(word[i]))
                {
                    mp[word[i]]--;
                    if (mp[word[i]] == 0)
                        mp.erase(word[i]);
                }
                else
                {
                    consonent--;
                }
                i++;
            }
            while (i < n && consonent == k && mp.size() == 5)
            {
                int idx = nextConsonent[j]; // this will tell me next consonent after jth index
                count += idx - j;           // imp part
                char ch = word[i];
                if (isVovel(ch))
                {
                    mp[ch]--;
                    if (mp[ch] == 0)
                        mp.erase(ch);
                }
                else
                {
                    consonent--;
                }
                i++;
            }
            j++;
        }
        return count;
    }
};
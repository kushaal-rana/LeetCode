class Solution
{
public:
    // Time Complexity: O(N*26*WordLength)
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end()); // SC: O(N)
        st.erase(beginWord);                                        // if visited we delete from the set.
        while (!q.empty())
        { // O(N)
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == endWord)
                return steps;
            // word = hat
            for (int i = 0; i < word.size(); i++)
            { // word Length  = 10
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {                 // O(26)
                    word[i] = ch; // aat, bat, cat.. you will check these in set.
                    if (st.find(word) != st.end())
                    {                   // if it exists in set
                        st.erase(word); // mark visited by deleting it.
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
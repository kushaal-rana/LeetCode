// Approach-1 (Using simple backtracking standard Template)
// T.C : O(n!)
// S.C : O(n * n!), total possible sequences = n! and each having n length
class Solution
{
public:
    void solve(string &tiles, string curr, vector<int> &used, unordered_set<string> &result)
    {
        result.insert(curr);
        // Always resultart from 0 to get all permutations
        for (int i = 0; i < tiles.size(); i++)
        {
            if (used[i] == true)
                continue;
            // Do
            used[i] = true;
            curr.push_back(tiles[i]);
            // Explore
            solve(tiles, curr, used, result);
            // UNDO backtrack
            used[i] = false;
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles)
    {
        unordered_set<string> result;
        vector<int> used(tiles.size() + 1, 0);
        solve(tiles, "", used, result);
        return result.size() - 1; // exclude the empty sequence.
    }
};
// Approach-2 (Using count of characters + backtracking)
// T.C : O(n!)
// S.C : O(n), total possible sequences = n! and each having n length
class Solution
{
public:
    int count;
    void solve(vector<int> vec)
    {
        count++;
        for (int i = 0; i < 26; i++)
        { // always start from i=0;
            if (vec[i] == 0)
                continue;
            vec[i]--;   // DO
            solve(vec); // Explore
            vec[i]++;   // UNDO
        }
    }
    int numTilePossibilities(string tiles)
    {
        count = 0;
        vector<int> vec(26, 0);
        for (char &ch : tiles)
        {
            vec[ch - 'A']++;
        }
        solve(vec);
        return count - 1; // exclude the empty subsequence
    }
};
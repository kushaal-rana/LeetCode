// Approach-1 (Using array and hashmap)
// T.C : O(n)
// S.C : O(limit) - This will cause MLE
class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> colorMp; // color->count
        vector<int> result(queries.size());
        vector<int> ballArr(limit + 1, -1); // ball[i] = xcolor
        for (int i = 0; i < queries.size(); i++)
        {
            int ball = queries[i][0];
            int color = queries[i][1];
            if (ballArr[ball] != -1)
            {
                int prevColor = ballArr[ball];
                colorMp[prevColor]--;
                if (colorMp.count(prevColor) == 0)
                {
                    colorMp.erase(prevColor);
                }
            }
            colorMp[color]++;
            ballArr[ball] = color;
            result[i] = colorMp.size(); // as it stores unique colors
        }
        return result;
    }
};

// Approach-2 (Using hashmaps)
// T.C : O(n)
// S.C : O(n)
class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> colorMp; // color->count
        unordered_map<int, int> ballMp;  // color->count
        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int ball = queries[i][0];
            int color = queries[i][1];
            if (ballMp.count(ball)) // already colored ball present in map
            {
                int prevColor = ballMp[ball];
                colorMp[prevColor]--;
                if (colorMp[prevColor] == 0)
                {
                    colorMp.erase(prevColor);
                }
            }
            colorMp[color]++;
            ballMp[ball] = color;
            result[i] = colorMp.size(); // as it stores unique colors
        }
        return result;
    }
};
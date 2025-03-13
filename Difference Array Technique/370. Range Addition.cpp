class Solution
{
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates)
    {
        vector<int> result(length);
        for (auto &query : updates)
        {

            int left = query[0];
            int right = query[1];
            int val = query[2];

            result[left] += val;
            if (right + 1 < length)
                result[right + 1] -= val;
        }
        for (int i = 0; i < length - 1; i++)
        {
            result[i + 1] += result[i];
        }
        return result;
    }
};
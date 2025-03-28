// Approach: Brute Force
// TC: O(n^2 * m)
class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        // store all the supplies in set
        unordered_set<string> st(supplies.begin(), supplies.end());
        int n = recipes.size();
        vector<bool> cooked(n, false);
        vector<string> result;
        int count = n;
        while (count--)
        { // O(n)
            for (int i = 0; i < n; i++)
            { // O(n)
                if (cooked[i])
                {
                    continue;
                }
                bool banPayega = true;
                for (int j = 0; j < ingredients[i].size(); j++)
                { // O(m)
                    if (!st.count(ingredients[i][j]))
                    {
                        banPayega = false;
                        break;
                    }
                }
                if (banPayega == true)
                {
                    result.push_back(recipes[i]);
                    st.insert(recipes[i]);
                    cooked[i] = true;
                }
            }
        }
        return result;
    }
};

// Approach: Topological Sort

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        // store all the supplies in set
        int n = recipes.size();
        unordered_set<string> st(supplies.begin(), supplies.end());

        // adj
        unordered_map<string, vector<int>> adj; // ing --> recipie

        // O(V+E)
        // O(n + m + S(set mail dalne ke liye))
        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (string &ingr : ingredients[i])
            {
                if (!st.count(ingr))
                {
                    adj[ingr].push_back(i); // ingred ->(recipe) so ye ingre se ye recipe banega recipie is dependent on ingredent
                    inDegree[i]++;
                }
            }
        }
        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                que.push(i);
            }
        }
        vector<string> result;
        while (!que.empty())
        {
            int front = que.front();
            que.pop();
            string recipe = recipes[front];
            result.push_back(recipe);

            for (int &idx : adj[recipe])
            {
                inDegree[idx]--;
                if (inDegree[idx] == 0)
                {
                    que.push(idx);
                }
            }
        }
        return result;
    }
};
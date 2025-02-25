// Approach 1 Brute Force. Go to each node and calculate height. (O(V*(V+E))=>O()V^2)
int solve(int root, map<int, vector<int>> adj, vector<int> visited)
{
    visited[root] = 1;
    int height = 0;
    for (auto node : adj[root])
    {
        if (!visited[node])
        {
            height = max(height, 1 + solve(node, adj, visited)); // finding out the height hence we are using max. See height of tree code.
        }
    }
    return height;
}
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    map<int, vector<int>> adj;
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mini = INT_MAX;
    vector<int> visited(n), ans;
    for (int i = 0; i < n; i++)
    {
        int height = solve(i, adj, visited);
        if (height < mini)
        { // if we get minimum height then only we clear the vector and push it
            ans.clear();
            ans.push_back(i);
            mini = height;
        }
        else if (height == mini)
            ans.push_back(i); // if not minimum we just add.
    }
    return ans;
}

class Solution
{
public:
    // Approach 2: Optimal: Using Topological Sort: Use BFS. Take leaf node find indegree and go to thier neighbours ultimately we reach center and that is our answer. TC: O(V+E)
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n);

        if (n == 1)
            return {0};
        // Forming Graph
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
            {
                q.push(i); // pushing leaf nodes
            }
        }
        while (n > 2)
        { // untill we get less that 2 nodes
            int size = q.size();
            n -= size;
            while (size--)
            {
                int u = q.front(); // take the leaf node
                q.pop();
                for (int &v : adj[u])
                { // take out neighbour of leaf node
                    indegree[v]--;
                    if (indegree[v] == 1)
                    { // if leaf node then only push
                        q.push(v);
                    }
                }
            }
        }
        vector<int> result;
        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};

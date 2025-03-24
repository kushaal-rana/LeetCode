class Solution
{
public:
    /*
    Approach: 1. Check if both belong to same component.(are connected):-> DSU
              2. Now whenever you take & the answer always reduces:-> take & of all the edges in component.
              3. When calculating parent do the cost of & with parent and store it in cost[]
              4. Now Process the query by seeing if they have same parent

    */
    // T.C :
    /*
        The time complexity of the union-find operations (with path compression) is approximately O(α(n)),
        where α is the inverse Ackermann function, which is practically constant for all reasonable values of n.
        The time complexity of processing each edge and each query is O(1).
        Therefore, the overall time complexity of the algorithm is O(E + Qα(n)), where E is the number of edges,
        Q is the number of queries, and α(n) is the inverse Ackermann function.
    */
    // S.C : O(n)
    class DSU
    {
    public:
        vector<int> parent;
        vector<int> rank;
        DSU(int n)
        {
            rank.resize(n, 0);
            parent.resize(n);
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }
        int find(int x)
        {
            if (x == parent[x])
                return x;
            return parent[x] = find(parent[x]);
        }
        void Union(int x, int y)
        {
            parent[y] = x;
            // int x_parent = find(x);
            // int y_parent = find(y);
            // if(x_parent==y_parent) return;
            // if(rank[x_parent]<rank[y_parent]){
            //     parent[x_parent] = y_parent;
            // }
            // else if(rank[y_parent]<rank[x_parent]){
            //     parent[y_parent] = x_parent;
            // }
            // else{
            //     parent[y_parent] = x_parent;
            //     rank[x_parent]++;
            //  }
        }
    };
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        DSU dsu(n);
        vector<int> cost(n, -1); //-1 & anyNumber=ThatNumber
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            int parentU = dsu.find(u);
            int parentV = dsu.find(v);

            if (parentU != parentV)
            {
                dsu.Union(parentU, parentV);
                cost[parentU] &= cost[parentV];
            }
            cost[parentU] &= wt;
        }
        // Handle Queries
        vector<int> result;
        for (auto &que : query)
        {
            int source = que[0];
            int target = que[1];

            int parentS = dsu.find(source);
            int parentT = dsu.find(target);

            if (source == target)
            {
                result.push_back(0);
            }
            else if (parentS != parentT)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(cost[parentS]);
            }
        }
        return result;
    }
};
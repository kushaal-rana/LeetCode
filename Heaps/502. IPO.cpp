class Solution
{
    // TC: worst case: NLogN
    // SC: O(N);
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> vec;
        int n = capital.size();
        for (int i = 0; i < n; i++)
        {
            vec.push_back({capital[i], profits[i]});
        }
        // O(NlogN)
        sort(begin(vec), end(vec)); // sort based on capital value.
        int i = 0;
        priority_queue<int> pq;
        // Heap max size would be all the elements inside heap as you have lot of money k==N
        while (k--)
        { // Imp do till k projects only
            while (i < n && vec[i].first <= w)
            {
                pq.push(vec[i].second); // once push logN
                i++;
            }
            // forgot this condtion
            if (pq.empty())
                break;

            w += pq.top();
            pq.pop(); // once pop log(N)
        }
        return w;
    }
};
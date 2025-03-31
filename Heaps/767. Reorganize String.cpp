class Solution
{
public:
    // Approach: Store frequency of character & if any char freq > (n+1)/2 return ""
    //  Max Heap {}
    string reorganizeString(string s)
    {
        int n = s.size();
        vector<int> count(26, 0);
        for (char ch : s)
        {
            count[ch - 'a']++;
            if (count[ch - 'a'] > (n + 1) / 2)
                return "";
        }
        priority_queue<pair<int, char>> pq;
        /*
            for(int i=0;i<n;i++){
                char ch = i+'a';
                if(count[i]>0){
                    pq.push ({count[i],ch})
                }
            } both will work
        */
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (count[ch - 'a'] > 0)
            {
                pq.push({count[ch - 'a'], ch});
            }
        }
        string result = "";
        // O(26 = k) O(k)
        while (pq.size() >= 2)
        {
            auto p1 = pq.top(); // O(log(26))
            pq.pop();
            auto p2 = pq.top(); // O(log(k))
            pq.pop();

            result.push_back(p1.second);
            result.push_back(p2.second); // O(n)
            p1.first--;
            p2.first--;
            if (p1.first > 0)
                pq.push(p1);
            if (p2.first > 0)
                pq.push(p2);
        }
        if (!pq.empty())
        {
            result.push_back(pq.top().second);
        }
        return result;
    }
};
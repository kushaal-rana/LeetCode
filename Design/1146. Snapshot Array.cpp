class SnapshotArray
{
public:
    int snap_id;
    // TC: O(N*logN)
    vector<vector<pair<int, int>>> vec; // idx->{snapid, value}
    int ownUpperBound(int index, int snap_id)
    {
        int l = 0, r = vec[index].size() - 1;
        int result = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (vec[index][mid].first <= snap_id)
            {
                result = vec[index][mid].second;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return result;
    }
    // unordered_map<int,vector<pair<int,int> mp;
    SnapshotArray(int length) : snap_id(0)
    {
        vec.resize(length);
        for (int i = 0; i < length; i++)
        {
            vec[i].push_back(make_pair(0, 0));
        }
    }

    void set(int index, int val)
    {
        vec[index].push_back({snap_id, val});
    }

    int snap()
    {
        snap_id += 1;
        return snap_id - 1;
        // return snap_id++;//smart way to do as first snap_id will return then ++
    }

    int get(int index, int snap_id)
    {
        // log(N)
        return ownUpperBound(index, snap_id);
        //    auto it = upper_bound(begin(vec[index]),end(vec[index]),make_pair(snap_id,INT_MAX));
        // pair(snap_id, val)
        // it--;
        // return prev(it)->second;//return value;
        // return it->second;
    }
};

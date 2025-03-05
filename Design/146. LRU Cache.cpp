// Approach-1 : Using vector of pair
//  T.C : O(N*N) as erase operation in vector is O(N)
// SC: O(N)
class LRUCache
{
public:
    vector<pair<int, int>> cache;
    int n;
    LRUCache(int capacity)
    {
        n = capacity;
    }

    int get(int key)
    {
        for (int i = 0; i < cache.size(); i++)
        {
            if (cache[i].first == key)
            {
                int val = cache[i].second;
                pair<int, int> temp = cache[i];
                cache.erase(begin(cache) + i);
                cache.push_back(temp);
                return val;
            }
        }
        return -1;
    }

    void put(int key, int value)
    {
        for (int i = 0; i < cache.size(); i++)
        {
            if (cache[i].first == key)
            {                                   // if already found the same key
                cache.erase(cache.begin() + i); // this is O(N)
                cache.push_back({key, value});
                return;
            }
        }
        // else notfound and first entry
        //  2 Cases:
        if (cache.size() == n)
        {
            cache.erase(cache.begin());
            cache.push_back({key, value});
        }
        else
        {
            cache.push_back({key, value});
        }
    }
};
// Approach-2 : Optimal Approach using Linked List (Double Linked List)
//  T.C : O(1) for both get and put
// SC: O(N)
// TC: O(1)For Get,Put,And makeRecentlyUsed
class LRUCache
{
public:
    list<int> dll;                               // key dalo
    map<int, pair<list<int>::iterator, int>> mp; // the address type is given by iterator
    int n;
    LRUCache(int capacity)
    {
        n = capacity;
    }

    void makeRecentlyUsed(int key)
    {
        dll.erase(mp[key].first); // I am passing the address/iterator so O(1)
        dll.push_front(key);      // push O(1)
        mp[key].first = dll.begin();
        // mp[key].second would be same value only changing address as we used recenlty.
    }
    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        makeRecentlyUsed(key);
        return mp[key].second;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        { // present in map
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else
        { // not present in map
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--; // one entry added
        }
        if (n < 0)
        {
            int key_to_be_deleted = dll.back(); // list has key & last ele should be deleted
            mp.erase(key_to_be_deleted);        // remove from mp
            dll.pop_back();                     // delete from list.
            n++;                                // once deleted now we can add more so n++;
        }
    }
};
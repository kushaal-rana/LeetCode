class LFUCache
{
public:
    int capacity;
    int size;
    unordered_map<int, list<vector<int>>::iterator> mp; // key->Address
    map<int, list<vector<int>>> freq;                   // counter->{key,val,freq/counter}

    LFUCache(int capacity) : capacity(capacity), size(0)
    {
    }
    void makeMostFrequentlyUsed(int key)
    {
        auto &vec = *(mp[key]); // & reference: any change in vec will change in map too
        int value = vec[1];
        int counter = vec[2];
        freq[counter].erase(mp[key]);
        if (freq[counter].empty())
        {
            freq.erase(counter);
        }
        counter++; // lfu
        freq[counter].push_front({key, value, counter});
        // change in mp also
        mp[key] = freq[counter].begin(); // address
    }
    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        // int value = *(mp[key])[2];
        auto vec = *(mp[key]); //{key, value,counter}
        int value = vec[1];
        // mark it as most frequently used
        makeMostFrequentlyUsed(key);
        return value;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;
        if (mp.find(key) != mp.end())
        { // key already present in map

            auto &vec = *(mp[key]); //{key,value,counter}
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }
        else if (size < capacity)
        { // you can put new element
            size++;
            freq[1].push_front(vector<int>({key, value, 1}));
            // freq[1].push_back({key,value,1});
            mp[key] = freq[1].begin(); // list hai tho uska first address
        }
        else
        { // Time to remove LFU, or LRU when ther is a tie

            auto &konsa_list = freq.begin()->second;    // you got whole dll
            int key_to_delete = (konsa_list.back())[0]; // delete back wale ko karna hai
            konsa_list.pop_back();
            if (konsa_list.empty())
            {
                freq.erase(freq.begin()->first); // similar to it.first(key), it.second(val)
            }
            freq[1].push_front({key, value, 1});

            mp.erase(key_to_delete);
            mp[key] = freq[1].begin();
        }
    }
};

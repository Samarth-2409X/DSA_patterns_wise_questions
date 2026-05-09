class LFUCache {
public:
    int cap;
    int size;

    unordered_map<int, list<vector<int>> :: iterator> mp;
    map<int, list<vector<int>>> freq;

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    void makyeMostFrequetlyUsed(int key){
        auto &vec = *(mp[key]);

        int value = vec[1];
        int f     = vec[2];

        freq[f].erase(mp[key]);

        if(freq[f].empty())
        freq.erase(f);

        f++;

        freq[f].push_front({key, value, f});

        mp[key] = freq[f].begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
        return -1;

        auto vec = (*(mp[key]));

        int value = vec[1];

        makyeMostFrequetlyUsed(key);

        return value;
    }

    void put(int key, int value) {
        if(cap == 0)
        return;

        if(mp.find(key) != mp.end()){
            auto &vec = (*(mp[key]));

            vec[1] = value;
           makyeMostFrequetlyUsed(key);
        }
        else if(size < cap){
            size ++;
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }
        else{
            auto &which_list = freq.begin() -> second;

            int key_to_del = (which_list.back())[0];
            which_list.pop_back();

            if(which_list.empty()){
                freq.erase(freq.begin() -> first);
            }

            freq[1].push_front(vector<int> ({key, value, 1}));

            mp.erase(key_to_del);
            mp[key] = freq[1].begin();
        }
    }
};


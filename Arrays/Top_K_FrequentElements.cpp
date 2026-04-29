class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        vector<vector<int>> bucket(n+1);

        for(int num: nums){
            mp[num]++;
        }

        for(auto &it:mp){
            int freq = it.second;
            int value = it.first;

            bucket[freq].push_back(value);
        }

        vector<int> result;

        for(int i=n; i>=0; i--){

            if(bucket[i].size() == 0) continue;

            while(bucket[i].size() > 0 && k > 0){
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }

        return result;
    }
};
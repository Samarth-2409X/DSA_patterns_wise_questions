class Solution {
public:
    vector<vector<int>> result;
    int n;

    void solve(unordered_map<int, int>& mp, vector<int>& temp){

        if(temp.size() == n){
            result.push_back(temp);
            return;
        }

        for(auto& [num, freq] : mp){
            if(freq == 0){
                continue;
            }

            temp.push_back(num);
            mp[num]--;

            solve(mp, temp);

            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();

        unordered_map<int, int> mp;

        vector<int> temp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        solve(mp, temp);

        return result;
    }
};
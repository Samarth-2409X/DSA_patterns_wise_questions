class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        map<int, int> mp;

        int cumS = 0;
        int result = 0;

        mp.insert({0, 1});

        for(int i=0; i<n; i++){
            cumS += nums[i];

            if(mp.find(cumS - k) != mp.end()){
                result += mp[cumS - k];
            }

            mp[cumS]++;
        }

        return result;
    }
};
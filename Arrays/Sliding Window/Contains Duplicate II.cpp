class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> s;

        for(int i=0; i<n; i++){
            if(s.find(nums[i]) != s.end()){
                if(abs(s[nums[i]] - i) <= k) return true;
            }

            s[nums[i]] = i;
        }

        return false;

    }
};
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mp;

        int currS = 0;
        mp[0] = -1;
        int result = 0;

        for(int i=0; i<n; i++){
            
            currS += (nums[i] == 0) ? -1 : 1;

            if(mp.find(currS) != mp.end()){
                result = max(result, i - mp[currS]);
            }
            else{
                mp[currS] = i;
            }
        }


        return result;
    }
};
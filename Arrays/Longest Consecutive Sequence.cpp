class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;

        for(auto num : s){
            if(s.find(num - 1) != s.end()){
                continue;
            }

            int current = num;
            int count = 0;

            while(s.find(current) != s.end()){
                count++;
                current++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};
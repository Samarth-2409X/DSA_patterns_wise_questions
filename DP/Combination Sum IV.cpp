#include <cstring>
class Solution {
public:
    int n;
    int t[201][1001];
    int solve(int idx, vector<int>& nums, int target){
        if(target == 0){
            return 1;
        }

        if(target < 0 || idx >= n){
            return 0;
        }

        if(t[idx][target] != -1){
            return t[idx][target];
        }

        int take = solve(0, nums, target - nums[idx]);

        int not_take = solve(idx + 1, nums, target);

        return t[idx][target] = take + not_take;

    }

    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));

        return solve(0, nums, target);
    }
};
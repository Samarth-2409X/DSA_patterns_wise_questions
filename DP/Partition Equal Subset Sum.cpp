class Solution {
public:
    int n;
    int t[201][20001];
    bool solve(vector<int>& nums, int i, int x){
        if(x == 0){
            return 1;
        }

        if(i >= n){
            return 0;
        }

        if(t[i][x] != -1){
            return t[i][x];
        }

        bool take = 0;
        if(nums[i] <= x){
            take = solve(nums, i+1, x - nums[i]);
        }

        bool skip = solve(nums, i+1, x);

        return t[i][x] = take || skip;
        
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int S = accumulate(begin(nums), end(nums), 0);

        memset(t, -1, sizeof(t));

        if(S % 2 != 0){
            return false;
        }

        int x = S/2;

        return solve(nums, 0, x);
    }
};
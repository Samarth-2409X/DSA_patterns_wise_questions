class Solution {
public:
    int t[46];

    int solve(int n){
        if(n < 0) return 0;

        if(n == 0) return 1;

        if(t[n] != -1){
            return t[n];
        }

        int OneStep = solve(n-1);

        int TwoStep = solve(n-2);

        return t[n] = OneStep + TwoStep;
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};
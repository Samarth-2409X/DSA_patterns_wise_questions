class Solution {
public:
    int t[10001];
    int solve(vector<int>& coins, int amount){

        if(amount == 0){
            return 0;
        }

        if(amount < 0){
            return INT_MAX;
        }

        if(t[amount] != -1){
            return t[amount];
        }

        int ans = INT_MAX;

        for(int coin: coins){
            int result = solve(coins, amount - coin);

            if(result != INT_MAX){
                ans = min(ans, 1+result);
            }
        }

        return t[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {

        memset(t, -1, sizeof(t));
        int ans = solve(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};
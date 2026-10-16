class Solution {
public:
    int n, stonesSum, target;
    int t[31][3001];

    int solve(vector<int>& stones, int i, int total){
        if(total >= target || i == n){
            return abs(total - (stonesSum - total));
        }

        if(t[i][total] != -1){
            return t[i][total];
        }

        int take = solve(stones, i+1, total + stones[i]);
        int skip = solve(stones, i+1, total);

        return t[i][total] = min(take, skip);
    }
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();

        for(int x: stones){
            stonesSum += x;
        }

        memset(t, -1, sizeof(t));

        target = (stonesSum +1) / 2;

        return solve(stones, 0, 0);
    }
};
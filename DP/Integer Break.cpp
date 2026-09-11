#include <cstring>
class Solution {
public:
    int t[59];

    int solve(int n){
        if(n == 1){
            return 1;
        }

        int result = INT_MIN;

        if(t[n] != -1){
            return t[n];
        }

       for(int i=1; i<=n-1; i++){
        int prod = i * max(n-i, solve(n-i));
        
        result = max(result, prod);
       }

        return t[n] = result;
    }

    int integerBreak(int n){
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};
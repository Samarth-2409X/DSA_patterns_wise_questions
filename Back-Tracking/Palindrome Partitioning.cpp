class Solution {
public:
    vector<vector<string>> result;
    int n;

    bool isPalindrom(string& s, int l, int r){

        while(l < r){
            if(s[l] != s[r]){
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

    void solve(string& s, int idx, vector<string>& temp){
        if(idx == n){
            result.push_back(temp);
            return;
        }

        for(int i=idx; i<n; i++){
            if(isPalindrom(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));

                solve(s, i+1, temp);

                temp.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        n = s.length();

        vector<string> temp;

        solve(s, 0, temp);

        return result;    
    }
};
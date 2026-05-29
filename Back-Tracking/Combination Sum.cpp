class Solution {
public:
    vector<vector<int>> result;
    set<vector<int>> st;

    void solve(vector<int>& candidates,int i, vector<int>& temp, int tar){

        if(tar == 0){
            if(st.find(temp) == st.end()){
                result.push_back(temp);
                st.insert(temp);
            }
            return;
        }

        if(i == candidates.size() || tar < 0){
            return;
        }

        temp.push_back(candidates[i]);
        solve(candidates, i+1, temp, tar - candidates[i]);
        solve(candidates, i, temp, tar - candidates[i]);
        temp.pop_back();

        solve(candidates, i+1, temp, tar);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;

        solve(candidates, 0, temp, target);

        return result;
    }
};
class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& candidates, int i, vector<int>& temp, int tar){
        if(tar == 0){
            result.push_back(temp);
            return;
        }

        if(tar < 0 || i >= candidates.size()){
            return;
        }

        temp.push_back(candidates[i]);
        solve(candidates, i+1, temp, tar - candidates[i]);
        temp.pop_back();

        int idx = i+1;
        while(idx < candidates.size() && candidates[idx] == candidates[idx - 1]){
            idx++;
        }

        solve(candidates, idx, temp, tar);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> temp;

        solve(candidates, 0, temp, target);

        return result;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        if(strs.empty()){
            return "";
        }

        string prifix = strs[0];

        for(int i=0; i<n; i++){
            int j = 0;

            while(j < prifix.size() && j < strs[i].size() && prifix[j] == strs[i][j]){
                j++;
            }

            prifix = prifix.substr(0, j);

            if(prifix == "") break;
        }

        return prifix;
    }
};
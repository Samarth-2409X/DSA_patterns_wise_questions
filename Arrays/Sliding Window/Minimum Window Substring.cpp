class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        unordered_map<char, int> mp;

        for(char &ch: t){
            mp[ch]++;
        }

        int i=0;
        int j=0;
        int countRequired = t.length();
        int minwindow = INT_MAX;
        int start_i = 0;


        while(j < n){
            if(mp[s[j]] > 0){
                countRequired--;
            }
            mp[s[j]]--;

            while(countRequired == 0){
                if(j-i+1 < minwindow){
                    minwindow = j-i+1;
                    start_i = i;
                }

                mp[s[i]]++;
                
                if(mp[s[i]] > 0){
                    countRequired ++;
                }
                i++;
            }
            j++;
        }

        return minwindow == INT_MAX ? "" : s.substr(start_i, minwindow);
    }
};
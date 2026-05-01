class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        int i =0;
        int j =0;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(char &ch: s1){
            freq1[ch - 'a']++;
        }

        while(j < n){
            freq2[s2[j] - 'a']++;

            if(j-i+1 > m){
                freq2[s2[i] - 'a']--;
                i++;
            }

            if(freq1 == freq2){
                return true;
            }

            j++;
        }

        return false;
    }
};
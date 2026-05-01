class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int n = s.length();

        int i=0;
        int j=0;
        int maxfreq = 0;
        int maxlen  = 0;

        while(j < n){
            freq[s[j] - 'A']++;
            maxfreq = max(maxfreq, freq[s[j] - 'A']);

            if(j-i+1 - maxfreq > k){
                freq[s[i] - 'A']--;
                i++;
            }

            maxlen = max(maxlen, j-i+1);
            j++;
        }

        return maxlen;
    }
};


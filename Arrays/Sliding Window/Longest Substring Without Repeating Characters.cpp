class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int freq[256] = {0};

        int i = 0;
        int j = 0;

        int ans = 0;
        
        while(j < n){
            freq[s[j]]++;

            while(freq[s[j]] > 1){
                freq[s[i]]--;
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};


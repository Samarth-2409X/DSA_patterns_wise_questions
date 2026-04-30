class Solution {
public:
    bool validPalindrome(string s) {
        
        int st = 0;
        int e = s.length() -1;

        while(st < e){
            if(s[st] != s[e]){
                return (ispalindrome(s, st+1, e) || ispalindrome(s, st, e-1));
            }
            st ++;
            e --;
        }

        return true;
    }

    bool ispalindrome(string& s, int st, int e){
        while(st < e){
            if(s[st] != s[e])
            return false;

            st++;
            e--;
        }
        return true;
        
    }
};
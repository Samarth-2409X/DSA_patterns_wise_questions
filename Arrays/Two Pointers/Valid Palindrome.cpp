class Solution {
public:
    bool isAlpha(char ch){
        if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();

        int st = 0;
        int  e = n-1;

        while(st < e){
            if(!isAlpha(s[st])){
                st++;
            }
            else if(!isAlpha(s[e])){
                e--;
            }
            else{
                if(tolower(s[st]) != tolower(s[e]))
                return false;
                st++;
                e--;
            }
        }
    

        return true;
    }
};
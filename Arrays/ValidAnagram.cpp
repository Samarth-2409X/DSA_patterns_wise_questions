class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);

        for(auto &ch: s){
            count[ch - 'a']++;
        }

        for(auto &ch: t){
            count[ch - 'a']--;
        }

        bool allzero = all_of(begin(count), end(count), [](int element){
            return element == 0;
        });

        return allzero;
    }
};
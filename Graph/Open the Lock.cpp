class Solution {
public:
    void fillNeighbor(queue<string>& que, string& curr, unordered_set<string>& st){

        for(int i=0; i<4; i++){
            int ch = curr[i];

            char dec = ch == '0' ? '9' : ch-1;
            char inc = ch == '9' ? '0' : ch+1;

            curr[i] = dec;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                que.push(curr);
            }

            curr[i] = inc;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                que.push(curr);
            }

            curr[i] = ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(begin(deadends), end(deadends));
        
        string start = "0000";

        if(st.find(start) != st.end()){
            return -1;
        }

        queue<string> que;
        que.push(start);

        int level = 0;

        while(!que.empty()){
            int size = que.size();

            while(size --){
                string curr = que.front();
                que.pop();

                if(curr == target){
                    return level;
                }

                fillNeighbor(que, curr, st);
            }
            level++;
        }

        return -1;
    }
};
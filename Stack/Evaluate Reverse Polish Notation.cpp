class Solution {
public:
    int Operator(int a, int b, string token){
        if(token == "+"){
            return a+b;
        }
        if(token == "-"){
            return a-b;
        }
        if(token == "*"){
            return a*b;
        }
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string &token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int result = Operator(b, a, token);

                st.push(result);
            }
            else{
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
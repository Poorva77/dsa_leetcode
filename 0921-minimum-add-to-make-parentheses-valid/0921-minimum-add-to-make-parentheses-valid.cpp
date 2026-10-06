class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count=0;
        for(char ch:s){
            if(ch=='('){
                st.push(ch);
                count++;
            }
            else{
                if(st.empty()) count++;
                else{
                    if(st.top()=='('){
                        st.pop();
                        count--;
                    }
                }
            }
        }
        return count;
    }
};
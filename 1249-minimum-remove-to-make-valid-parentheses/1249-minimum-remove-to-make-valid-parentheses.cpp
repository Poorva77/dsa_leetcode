class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0;
        string ans;
        string finalAns;
        for(char ch:s){
            if(ch=='('){
                open++;
                ans.push_back(ch);
            }
            else if(ch==')'){
                if(open>0){
                    open--;
                    ans.push_back(ch);
                }
            }
            else{
                ans.push_back(ch);
            }
        }
        // Remove extra '(' from right
        for(int i = ans.size()-1; i >= 0; i--){  //start from right & loop until open!=0 at end
            if(ans[i]=='(' && open>0){
                open--;
                continue;
            }
            finalAns.push_back(ans[i]);
        }
        reverse(finalAns.begin(), finalAns.end());  //very IMP
        return finalAns;
    }
};
//TC=0(1)
class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int open=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            } 
            else{
                //check if we have a pair '))'
                if(i+1<n && s[i+1]==')'){
                    i++; //skip the second ')'
                } 
                else ans++; //add ')'

                //when we HAVE '))'
                if(open>0) open--;
                else{
                    ans++; //adds '('
                }
            }
        }
        return ans+2*open;
    }
};
class Solution {
public:
    //new method 
    vector<string> ans;
    bool checkIfValid(string s){  
        int count=0;
        for(char ch:s){
            if(ch=='(') count++;
            else count--;
            if(count<0) return false;  //very IMP
        }
        return count==0;
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        for(int i=0;i<n;i++) s.push_back('(');
        for(int i=0;i<n;i++) s.push_back(')');
        if(checkIfValid(s)){
            ans.push_back(s);   //this first combination is always possible - see () or (()) or ((()))...
        }
        while(next_permutation(s.begin(),s.end())){
            if(checkIfValid(s)){
                ans.push_back(s);   
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool checkIfValid(string v){  
        int count=0;
        for(char ch:v){
            if(ch=='(') count++;
            else if(ch==')') count--;
            if(count<0) return false;  //very IMP
        }
        return count==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q;
        set<string> visited;
        q.push(s);
        visited.insert(s);
        bool found=false;

        while(!q.empty() && !found){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();

                if(checkIfValid(curr)){
                    ans.push_back(curr);
                    found=true;
                    continue;
                }

                //hint1- try removing each parenthesis one by one..
                for(int i=0;i<curr.size();i++){
                    //don't remove normal characters (testcase 2)
                    if(curr[i]!='(' && curr[i]!=')')
                        continue;

                    string v=curr;
                    v.erase(i,1);

                    if(visited.find(v)==visited.end()){
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }
        }
        return ans;
    }
};
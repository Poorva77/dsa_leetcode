class Solution {
public:
    long long sumAndMultiply(int n) {
        string s= to_string(n);
        string x;
        int sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                x.push_back(s[i]);
                sum+=(s[i]-'0');   //Fixed: Subtracted '0' to get actual DIGIT value
            }
        }
        if(x.size()==0){
            return 0;
        }
        long long newX= stoll(x);
        return newX*sum;
    }
};
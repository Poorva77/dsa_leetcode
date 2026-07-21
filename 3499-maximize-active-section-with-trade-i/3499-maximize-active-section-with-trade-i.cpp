class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones=0;
        for(char c:s)
            if(c=='1') ones++;
        int ans=ones;
        string t="1"+s+"1";
        int n=t.size();
        int i=1;
        while(i<n-1){
            if(t[i]=='0'){
                i++;
                continue;
            }
            int l=i;
            while(i<n-1 && t[i]=='1') i++;
            int r=i-1;
            if(t[l-1]!='0' || t[r+1]!='0')
                continue;
            int L=0;
            int x=l-1;
            while(x>=0 && t[x]=='0'){
                L++;
                x--;
            }
            int R=0;
            x=r+1;
            while(x<n && t[x]=='0'){
                R++;
                x++;
            }
            ans=max(ans,ones+L+R);
        }
        return ans;
    }
};
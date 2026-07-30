class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        for(int i=0;i<word.size();i++){
            ans+=(i/8)+1;  //every 8 letters need one extra push
        }
        return ans;
    }
};

//i thought very bad - 

/* class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        if(word.size()<=8){
            return word.size();
        }
        else{
            if(word.size()<=16){
                ans=8;
                int n=word.size()-8;
                ans+=n*2;
            }
            else{
                ans=8;
                int n=word.size()-8;
                ans+=n*2;
                n-=8;
                ans+=n*3;
            }
        }
        return ans;
    }
};
*/
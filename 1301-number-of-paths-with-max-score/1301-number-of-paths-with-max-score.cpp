class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        int MOD=1e9+7;

        vector<vector<long long>> dp(4,vector<long long>(n,0));

        string lastRow=board[n-1];
        dp[1][n-1]=1;

        for(int j=n-2;j>=0;j--){
            char c=lastRow[j];
            if(c=='X'||dp[1][j+1]==0)
                continue;

            dp[0][j]=dp[0][j+1]+(c-'0');
            dp[1][j]=dp[1][j+1];
        }

        vector<pair<int,int>> dirs={{0,1},{1,0},{1,1}};

        for(int i=n-2;i>=0;i--){
            string row=board[i];

            int cur=((n-1-i)%2==0)?0:2;
            int prv=(cur==0)?2:0;

            int sumC=cur;
            int cntC=cur+1;
            int sumP=prv;
            int cntP=prv+1;

            fill(dp[sumC].begin(),dp[sumC].end(),0);
            fill(dp[cntC].begin(),dp[cntC].end(),0);

            for(int j=n-1;j>=0;j--){
                char c=row[j];

                if(c=='X')
                    continue;

                long long best=-1,total=0;

                for(auto d:dirs){
                    int nj=j+d.first;

                    if(nj>=n)
                        continue;

                    int sumIdx=(d.second==1)?sumP:sumC;
                    int cntIdx=(d.second==1)?cntP:cntC;

                    if(dp[cntIdx][nj]==0)
                        continue;

                    if(dp[sumIdx][nj]>best){
                        best=dp[sumIdx][nj];
                        total=dp[cntIdx][nj];
                    }
                    else if(dp[sumIdx][nj]==best){
                        total=(total+dp[cntIdx][nj])%MOD;
                    }
                }

                if(best==-1)
                    continue;

                dp[sumC][j]=best+(c=='E'?0:c-'0');
                dp[cntC][j]=total;
            }
        }

        int finalCur=((n-1)%2==0)?0:2;

        long long finalSum=dp[finalCur][0];
        long long finalCnt=dp[finalCur+1][0];

        if(finalCnt==0)
            return {0,0};

        return {(int)finalSum,(int)finalCnt};
    }
};